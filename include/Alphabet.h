#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
#include <string>
#include <set>

#pragma once

class Alphabet {
  
  private:
    std::set<std::string> symbols_;

  public:
    Alphabet() {}
    ~Alphabet() {}
    void insertSymbol(std::string symbol);
    bool hasSymbol(std::string symbol);
    std::set<std::string> getAlphabet();

};

#endif // ALPHABET_H