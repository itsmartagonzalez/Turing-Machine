#include "Tape.h"

void Tape::setBlankSymbol(std::string blank) {
  blankSymbol_ = blank;
}

void Tape::setInput(std::string input) {
  for (int i = 0; i < input.length(); i++) {
    tape_.push_back(std::string(1,input[i]));
  }
  head_ = tape_.begin();
}

std::string Tape::getHeadValue() {
  return *head_;
}

void Tape::setHeadValue(std::string value) {
  *head_ = value;
}

void Tape::moveHead(std::string move) {
  if (move == "R") {
    std::advance(head_, 1);
    if (head_ == tape_.end()) {
      tape_.push_back(blankSymbol_);
      std::advance(head_, -1);
    }
  } else if (move == "L") {
    if (head_ == tape_.begin()) {
      tape_.push_front(blankSymbol_);
      head_ = tape_.begin();
    } else {
      std::advance(head_, -1);
    }
  } // if move = S, head stays the same
}

void Tape::print() {
  std::cout << "\nTape: ";
  for (auto x : tape_) {
    std::cout << x;
  }
  std::cout << "\n";
}