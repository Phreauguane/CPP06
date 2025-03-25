#pragma once

#include "ScalarConverter.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

namespace Utils {
    ScalarTypes getType(const std::string&);
    void convertSpecial(const std::string&);
    void convertChar(const std::string&);
    void convertInt(const std::string&);
    void convertFloat(const std::string&);
    void convertDouble(const std::string&);
    void printInvalid(const std::string&);
    extern void (*converters[6])(const std::string&);
}