#pragma once

#include <stdint.h>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

struct Data
{
	std::string name;
	int age;
	std::string sername;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer&);
        ~Serializer();
        Serializer &operator=(const Serializer&);
    public:
        static uintptr_t serialize(Data*);
        static Data *deserialize(uintptr_t);
};

std::ostream &operator<<(std::ostream &o, Data *a);