#include "ScalarConverter.h"
#include "Utils.h"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&src) {(void)src;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&src) {(void)src; return *this;}

void ScalarConverter::convert(const std::string&str) {
    ScalarTypes type = Utils::getType(str);
	(*Utils::converters[type])(str);
}
