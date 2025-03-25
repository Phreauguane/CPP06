#include "Serializer.h"
#include <iostream>

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer&src) { *this = src; }

Serializer &Serializer::operator=(const Serializer&src) { (void)src; return (*this); }

Serializer::~Serializer(void) {}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &o, Data *a) {
    o << "- "BLUE"Data structure :" << std::endl;
    o << YELLOW "address: " GREEN << (void*)a << RESET << std::endl;
    o << CYAN "name: " GREEN << a->name << RESET << std::endl;
    o << CYAN "age: " GREEN << a->age << RESET << std::endl;
    o << CYAN "sername: " GREEN << a->sername << RESET << std::endl;
    return o;
}
