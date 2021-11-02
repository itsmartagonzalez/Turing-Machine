#include "TuringMachine.h"
#include <filesystem>

int main(int argc, char *argv[]) {
  try {
    std::string input;
    std::cout << "\n======Welcome to the Turing Machine Simulator======\n→ This Machine writes and moves simultaneously.\n→ It recognizes the (L)eft, (R)ight and (S)tay movements.\n→ It's tape is infinite in both directions.";
    std::cout << "\n\nPlease, insert the path to your input file. You are currently in " << std::filesystem::current_path() << ":\n →";
    std::cin >> input;
    TuringMachine machine(input);
    std::cout << "\nThe Turing Machine has loaded successfully. Choose an option:";
    std::string option = "1";
    while (option != "0") {
      std::cout << "\n\n1. Insert an input string and start running the Turing Machine.\n0. Exit the program.\n → ";
      std::cin >> option;
      if (option == "1") {
        std::string input;
        std::cout << "\nIntroduce your input string:\n → ";
        std::cin >> input;
        machine.run(input);
      } else if(option == "0") {
        std::cout << "\nThank you for using this program. Have a nice day!\n";
      } else {
        std::cout << "\nInvalid Option. Please try again.\n";
      }
    }
  } catch (std::string& error) {
    std::cerr << error;
  }
}