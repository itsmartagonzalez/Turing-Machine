#ifndef TAPE_H
#define TAPE_H

#include <list>
#include "Alphabet.h"

#pragma once

class Tape {

  private:
    std::list<std::string> tape_;
    std::list<std::string>::iterator head_;
    std::string blankSymbol_;

  public:
    Tape() {}
    ~Tape() {}
    void setBlankSymbol(std::string blank);
    void setInput(std::string);
    std::string getHeadValue();
    void setHeadValue(std::string);
    void moveHead(std::string move);
    void print();
};

#endif //TAPE_H