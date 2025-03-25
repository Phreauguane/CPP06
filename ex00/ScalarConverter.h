#pragma once

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum ScalarTypes {
    INVALID  =  0,
    SPECIAL  =  1,
    CHAR     =  2,
    INT      =  3,
    FLOAT    =  4,
    DOUBLE   =  5 
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter&);
    public:
        static void convert(const std::string&);
};
