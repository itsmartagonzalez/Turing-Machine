#include "Alphabet.h"

void Alphabet::insertSymbol(std::string symbol) {
  symbols_.insert(symbol);
}

bool Alphabet::hasSymbol(std::string symbol) {
  if (symbols_.find(symbol) == symbols_.end()) {
    return false;
  }
  return true;
}

std::set<std::string> Alphabet::getAlphabet() {
  return symbols_;
}