#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include "State.h"
#include "Alphabet.h"
#include "Tape.h"
#pragma once

class TuringMachine {
  
  private:
    std::set<State> states_;
    Alphabet inputAlphabet_;
    Alphabet tapeAlphabet_; //Meter en clase cinta
    std::string currentState_;
    std::vector<Tape> tapes_;
    std::string blankSymbol_;

  public:
    TuringMachine(std::string data);
    ~TuringMachine() {}
    void run(std::string input);

  private:
    void createStates(std::string line, std::vector<State>& states);
    void createInputAlphabet(std::fstream& input);
    void createTapeAlphabet(std::fstream& input);
    void setInitialState(std::fstream& input, std::vector<State>& states);
    void setBlank(std::fstream& input);
    void initializeTapes(std::fstream& input, std::string blank);
    void setAcceptingStates(std::fstream& input, std::vector<State>& states);
    void setTransitions(std::fstream& input, std::vector<State>& states);
    
};

#endif // TURING_MACHINE_H