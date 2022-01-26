#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (size_t i = 1; i < (size_t)argc; i++) {
      std::string str = "";
      for (size_t j = 0; argv[i][j]; j++) {
        str += std::toupper(argv[i][j]);
      }
      std::cout << str;
    }
		std::cout << std::endl;
  }
}
