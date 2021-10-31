#ifndef TRANSITION_H
#define TRANSITION_H
#include <iostream>
#include <string>
#include <vector>
#include "State.h"

#pragma once

class State;

class Transition {
  
  private:
    std::string currentState_;
    std::vector<std::string> tapeSymbols_;
    std::string nextState_;
    std::vector<std::string> tapeInput_;
    std::vector<std::string> moves_;

  public:
    Transition() {}
    Transition(std::string currentState, std::vector<std::string> tapeSymbols, std::string nextState, std::vector<std::string> tapeInput, std::vector<std::string> moves);
    ~Transition() {}
    std::string getCurrentState() const;
    std::vector<std::string> getTapeSymbols() const;
    std::string getNextState() const;
    std::vector<std::string> getTapeInput() const;
    std::vector<std::string> getMoves() const;
    void print();

    bool operator==(const Transition& transition) const;
    bool operator<(const Transition& transition) const;
    bool operator>(const Transition& transition) const;
};


#endif // TRANSITION_H