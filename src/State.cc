#include "State.h"

State::State(std::string identifier) {
  identifier_ = identifier;
  accepted_ = false;
}

std::string State::getIdentifier() {
  return identifier_;
}

void State::setAccepted(bool accepted) {
  accepted_ = accepted;
}

bool State::isAccepted() {
  return accepted_;
}

void State::insertTransition(Transition transition) {
  transitions_.push_back(transition);
}

std::vector<Transition> State::getTransitions() {
  return transitions_;
}

void State::printTransitions() {
  for (auto t : transitions_) {
    t.print();
  }
}

bool State::operator==(const State& state) const {
  if (state.identifier_ != identifier_) {
    return false;
  }
  return true;
}

bool State::operator<(const State& state) const {
  if (state.identifier_ < identifier_) {
    return false;
  }
  return true;
}

bool State::operator>(const State& state) const {
  if (state.identifier_ > identifier_) {
    return false;
  }
  return true;
}