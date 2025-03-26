#include "Base.h"
#include <iostream>
#include <fstream>

Base::~Base() {}

unsigned int getRandom(unsigned int min, unsigned int max) {
    if (min > max) {
        std::swap(min, max);
    }

    unsigned int randomNum;
    std::ifstream randomFile("/dev/random", std::ios::in | std::ios::binary);
    
    if (!randomFile) {
        std::cerr << "Error: Unable to open /dev/random" << std::endl;
        return 0;
    }

    randomFile.read(reinterpret_cast<char*>(&randomNum), sizeof(randomNum));

    if (!randomFile) {
        std::cerr << "Error: Failed to read from /dev/random" << std::endl;
        return 0;
    }

    randomNum = randomNum % (max - min + 1) + min;

    return randomNum;
}

Base *generate(void) {
    int random = getRandom(0, 2);

    std::cout << YELLOW "-- generating " << (random == 0 ? (RED"A") : (random == 1 ? (GREEN"B") : (BLUE"C"))) << RESET << std::endl;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *ptr) {
    if (dynamic_cast<A*>(ptr))
        std::cout << RED "A" RESET << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << GREEN "B" RESET << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << BLUE "C" RESET << std::endl;
}

void identify(Base &ref) {
    try {
        A &a = dynamic_cast<A&>(ref); (void)a;
        std::cout << RED "A" RESET << std::endl; return;
    } catch (...) {}
    try {
        B &b = dynamic_cast<B&>(ref); (void)b;
        std::cout << GREEN "B" RESET << std::endl; return;
    } catch (...) {}
    try {
        C &c = dynamic_cast<C&>(ref); (void)c;
        std::cout << BLUE "C" RESET << std::endl; return;
    } catch (...) {}
}