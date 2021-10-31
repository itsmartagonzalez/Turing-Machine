#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <string>
#include <set>
#include "Transition.h"

#pragma once

class Transition;

class State {
  
  private:
    std::string identifier_;
    std::vector<Transition> transitions_;
    bool starter_; // borrar?
    bool accepted_;

  public:
    State() {}
    State(std::string identifier);
    ~State() {}
    void setIdentifier(std::string identifier);
    std::string getIdentifier();
    bool isStarter();
    void setStarter(bool starter);
    bool isAccepted();
    void setAccepted(bool accepted);
    void insertTransition(Transition transition);
    std::vector<Transition> getTransitions();
    void printTransitions();
    bool operator==(const State& state) const;
    bool operator<(const State& state) const;
    bool operator>(const State& state) const;

};


#endif // STATE_H