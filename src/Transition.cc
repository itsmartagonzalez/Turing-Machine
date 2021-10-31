#include "Transition.h"

Transition::Transition(std::string currentState, std::vector<std::string> tapeSymbols, std::string nextState, std::vector<std::string> tapeInput,  std::vector<std::string> moves) {
  currentState_ = currentState;
  tapeSymbols_ = tapeSymbols;
  nextState_ = nextState;
  tapeInput_ = tapeInput;
  moves_ = moves;
}

std::string Transition::getCurrentState() const {
  return currentState_;
}

std::vector<std::string> Transition::getTapeSymbols() const {
  return tapeSymbols_;
}

std::string Transition::getNextState() const {
  return nextState_;
}

std::vector<std::string> Transition::getTapeInput() const {
  return tapeInput_;
}

std::vector<std::string> Transition::getMoves() const {
  return moves_;
}

void Transition::print() {
  std::cout << "\n" << currentState_ << "\t";
  for (int i = 0; i < tapeSymbols_.size(); i++) {
    std::cout << tapeSymbols_[i] << " ";
  }
  std::cout << "\t" << nextState_ << "\t";
  for (int i = 0; i < tapeInput_.size(); i++) {
    std::cout << tapeInput_[i] << " ";
  }
  std::cout << "\t";
  for (int i = 0; i < moves_.size(); i++) {
    std::cout << moves_[i] << " ";
  }
  std::cout << "\n";
}

bool Transition::operator==(const Transition& transition) const {
  if (transition.getCurrentState() != currentState_ 
    || transition.getNextState() != nextState_ 
    || transition.getTapeSymbols() != tapeSymbols_
    || transition.getTapeInput() != tapeInput_
    || transition.getMoves() != moves_) {
    return false;
  }
  return true;
}

bool Transition::operator<(const Transition& transition) const {
  if (transition.getCurrentState() < currentState_ 
    || transition.getNextState() < nextState_ 
    || transition.getTapeSymbols() < tapeSymbols_
    || transition.getTapeInput() < tapeInput_
    || transition.getMoves() < moves_) {
    return false;
  }
  return true;
}

bool Transition::operator>(const Transition& transition) const {
  if (transition.getCurrentState() > currentState_ 
    || transition.getNextState() > nextState_ 
    || transition.getTapeSymbols() > tapeSymbols_
    || transition.getTapeInput() > tapeInput_
    || transition.getMoves() > moves_) {
    return false;
  }
  return true;
}