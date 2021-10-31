#include "TuringMachine.h"
#include <filesystem>

int main(int argc, char *argv[]) {
  try {
    if (argc < 2) {
      std::string error = "\nError: agruments are missing";
      throw error;
    } else {
      std::string input = argv[1];
      // std::cout << "\n Insert the path to your input file. You are currently in " << std::filesystem::current_path() << ":\n →";
      // std::cin >> input;
      TuringMachine machine(input);
      machine.run("0100010");
      /*std::cout << "\n======Welcome to the Pushdown-Automaton Simulator======";
      PDA pda(argv[1]);
      std::cout << "\nThe Automaton has loaded successfully. This PDA's stop condition is reaching an accepting state. Choose an option:";
      int option = 1;
      while (option != 0) {
        std::cout << "\n\n1. Insert an input string and start the Automaton.\n0. Exit the size.\n → ";
        std::cin >> option;
        if (option == 1) {
          std::string input;
          std::cout << "\nIntroduce your input string:\n → ";
          std::cin >> input;
          pda.run(input);
        } else if(option == 0) {
          std::cout << "\nThank you for using this program. Have a nice day!\n";
        } else {
          std::cout << "\nInvalid Option. Please try again.\n";
        }
      }*/
    }
  } catch (std::string& error) {
    std::cerr << error;
  }
}