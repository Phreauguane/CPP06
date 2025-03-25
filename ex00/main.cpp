#include "ScalarConverter.h"
#include "Utils.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED "enter a char/ int/ float/ double value" RESET << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}