#include "TuringMachine.h"

TuringMachine::TuringMachine(std::string data) {
  std::fstream input(data);
  if (input.fail()) {
    std::string error = "\nError opening file: " + data;
    throw error;
  } else {
    std::string line;
    std::vector<State> states;
    while(getline(input, line) && line[0] == '#');
    createStates(line, states);
    createInputAlphabet(input);
    createTapeAlphabet(input);
    setInitialState(input, states);
    setBlank(input);
    setAcceptingStates(input, states);
    initializeTapes(input, blankSymbol_);
    setTransitions(input, states);
  }
}

void TuringMachine::createStates(std::string line, std::vector<State>& states) {
  std::istringstream elements(line);
  while (elements >> line) {
    State state(line);
    states.push_back(state);
  }
}

void TuringMachine::createInputAlphabet(std::fstream& input) {
  std::string line;
  getline(input, line);
  std::istringstream elements(line);
  while (elements >> line) {
    inputAlphabet_.insertSymbol(line);
  }
}

void TuringMachine::createTapeAlphabet(std::fstream& input) {
  std::string line;
  getline(input, line);
  std::istringstream elements(line);
  while (elements >> line) {
    tapeAlphabet_.insertSymbol(line);
  }
  for (auto symbol : inputAlphabet_.getAlphabet()) {
    if (!tapeAlphabet_.hasSymbol(symbol)) {
      std::string error = "\nError: the symbol '" + symbol + "' defined in the input alphabet is not in the tape alphabet.\n";
      throw error;
    }
  }
}

void TuringMachine::setInitialState(std::fstream& input, std::vector<State>& states) {
  std::string line;
  getline(input, line);
  auto iter = std::find(states.begin(), states.end(), State(line));
  if (iter == states.cend()) {
    std::string error = "\nError: starting state '" + line + "' is not in the set of states.\n";
    throw error;
  }
  currentState_ = line;
}

void TuringMachine::setBlank(std::fstream& input) {
  std::string line;
  getline(input, line);
  blankSymbol_ = line;
}

void TuringMachine::setAcceptingStates(std::fstream& input, std::vector<State>& states) {
  std::string line;
  getline(input, line);
  std::istringstream elements(line);
  while (elements >> line) {
    auto iter = std::find(states.begin(), states.end(), State(line));
    if (iter == states.cend()) {
      std::string error = "\nError: accepted state '" + line + "' is not in the set of states.\n";
      throw error;
    }
    (*iter).setAccepted(true);
  }
}

void TuringMachine::initializeTapes(std::fstream& input, std::string blank) {
  std::string line;
  getline(input, line);
  tapes_.resize(std::stoi(line));
  for (int i = 0; i < tapes_.size(); ++i) {
    tapes_[i].setBlankSymbol(blank);
  }
}

void TuringMachine::setTransitions(std::fstream& input, std::vector<State>& states) {
  std::string line;
  while (getline(input, line)) {
    std::istringstream elements(line);
    elements >> line;

    // Current state
    auto currentState = std::find(states.begin(), states.end(), State(line));
    if (currentState == states.cend()) {
      std::string error = "\nError: current state '" + line + "' is not in the set of states.\n";
      throw error;
    }

    // Tape Symbols
    std::vector<std::string> tapeSymbols;
    for (int i = 0; i < tapes_.size(); i++) {
      elements >> line;
      if (!tapeAlphabet_.hasSymbol(line) && line != ".") {
        std::string error = "\nError: The tape alphabet does not contain the symbol '" + line + "'.\n";
        throw error;      
      } else {
        tapeSymbols.push_back(line);
      }
    }

    // Reads next state
    elements >> line;
    auto nextState = std::find(states.begin(), states.end(), State(line));
    if (nextState == states.cend()) {
      std::string error = "\nError: next state '" + line + "' is not in the set of states.\n";
      throw error;
    }

    // Tape Input
    std::vector<std::string> tapeInput;
    for (int i = 0; i < tapes_.size(); i++) {
      elements >> line;
      if (!tapeAlphabet_.hasSymbol(line) && line != ".") {
        std::string error = "\nError: The tape alphabet does not contain the symbol '" + line + "'.\n";
        throw error;
      } else {
        tapeInput.push_back(line);
      }
    }

    // Moves
    std::vector<std::string> moves;
    for (int i = 0; i < tapes_.size(); i++) {
      elements >> line;
      if (line == "R" && line == "L" && line == "S") {
        std::string error = "\nError: The movement '" + line + "' is not defined.\n";
        throw error;
      } else {
        moves.push_back(line);
      }
    }

    (*currentState).insertTransition(Transition(currentState->getIdentifier(), tapeSymbols, nextState->getIdentifier(), tapeInput, moves));
  }
  states_ = std::set<State>(states.begin(),states.end());
}

void TuringMachine::run(std::string input) {
  std::string current = currentState_;
  bool isRunning = true;
  
  for (auto& tape : tapes_) {
    tape.setInput(input);
  }
  
  while (isRunning) {
    isRunning = false;
    State state = *std::find(states_.begin(), states_.end(), State(current));
    for (auto currentTransition : state.getTransitions()) {      
      std::vector<std::string> currentTapesHeaders;
      for (int i = 0; i < tapes_.size(); i++) {
        currentTapesHeaders.push_back(tapes_[i].getHeadValue());
      }
      if (currentTapesHeaders == currentTransition.getTapeSymbols()) {
        currentTransition.print();
        for (int i = 0; i < tapes_.size(); i++) {
          tapes_[i].setHeadValue(currentTransition.getTapeInput()[i]);
          tapes_[i].moveHead(currentTransition.getMoves()[i]);
        }
        current = currentTransition.getNextState();
        isRunning = true;
        break;
      }
    }
  }
  State finalState = *(std::find(states_.begin(), states_.end(), State(current)));
  if (finalState.isAccepted()) {
    std::cout << "\n\nThe input string was accepted by the Turing Machine. Congratulations!\n\n";
  } else {
    std::cout << "\n\nThe input string was NOT accepted by the Turing Machine. Try another input!\n\n";
  }
  for (int i = 0; i < tapes_.size(); i++) {
    std::cout << "\nTape " << i + 1 << ": ";
    tapes_[i].print();
  }
}