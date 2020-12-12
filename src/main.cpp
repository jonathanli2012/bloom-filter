#include "bloom.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_usage() {
  std::cerr << "Usage: "
            << " <option(s)>\n"
            << "Options:\n"
            << "\th\t\tShow this help message\n"
            << "\ti <string>\tinsert\n"
            << "\tl <string>\tlookup\n"
            << "\tp\t\tprint filter\n"
            << std::endl;
}

int main(int argc, char *argv[]) {

  // Error handling arg mismatch
  if (argc != 2) {
    std::cerr << "Usage:\n"
              << "./bloom <int filter_size>\n"
              << "\tp\t\tprint filter\n"
              << std::endl;
    return -1;
  }

  int bloom_filter_size = std::stoi(argv[1], nullptr);
  BloomFilter *b_filter = new BloomFilter(bloom_filter_size);

  while (1) {
    std::cout << "> ";
    std::string command_line_text;
    std::getline(std::cin, command_line_text);

    // Quit
    if (command_line_text == "q") {
      delete b_filter;
      return 0;
    }

    // Instructions are one character in length
    char instruction = command_line_text[0];

    // If the instruction is > 1 in length, we print usage
    if (command_line_text[1] != ' ') {
      print_usage();
    }
    // Normal Execution
    else {
      // Remove instruction and space from string
      command_line_text.erase(0, 2);

      switch (instruction) {
      case 'a':
      case 'i':
        b_filter->add_string(command_line_text);
        break;
      case 'l':
        if (b_filter->lookup(command_line_text)) {
          std::cout << "lookup - " << command_line_text << ": TRUE\n";
        } else {
          std::cout << "lookup - " << command_line_text << ": FALSE\n";
        }
        break;
      case 'p':
        std::cout << "filter print: " << b_filter->expose_filter() << "\n";
        break;
      case 'h':
        print_usage();
        break;
      default:
        print_usage();
        break;
      }
    }
  }

  delete b_filter;
  return 0;
}