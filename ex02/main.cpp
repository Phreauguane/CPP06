#include "Base.h"
#include <iostream>

int main() {
    std::cout << YELLOW"-----------------"RESET << std::endl;

    //-- A --//
    std::cout << CYAN "--- Testing " RED "A" CYAN " ---" RESET << std::endl;
    {
        Base *ptr = new A();
        Base &ref = *ptr;

        std::cout << MAGENTA "- Pointer :" RESET << std::endl;
        identify(ptr);

        std::cout << MAGENTA "- Reference :" RESET << std::endl;
        identify(ref);
        
        delete ptr;
    }
    std::cout << YELLOW"-----------------"RESET << std::endl;
    
    //-- B --//
    std::cout << CYAN "--- Testing " GREEN "B" CYAN " ---" RESET << std::endl;
    {
        Base *ptr = new B();
        Base &ref = *ptr;

        std::cout << MAGENTA "- Pointer :" RESET << std::endl;
        identify(ptr);

        std::cout << MAGENTA "- Reference :" RESET << std::endl;
        identify(ref);
        
        delete ptr;
    }
    std::cout << YELLOW"-----------------"RESET << std::endl;


    //-- C --//
    std::cout << CYAN "--- Testing " BLUE "C" CYAN " ---" RESET << std::endl;
    {
        Base *ptr = new C();
        Base &ref = *ptr;

        std::cout << MAGENTA "- Pointer :" RESET << std::endl;
        identify(ptr);

        std::cout << MAGENTA "- Reference :" RESET << std::endl;
        identify(ref);

        delete ptr;
    }
    std::cout << YELLOW"-----------------"RESET << std::endl;

    std::cout << CYAN "--- Testing random (10 times)..." RESET << std::endl << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        Base *ptr = generate();
        Base &ref = *ptr;

        std::cout << MAGENTA "- Pointer :" RESET << std::endl;
        identify(ptr);

        std::cout << MAGENTA "- Reference :" RESET << std::endl;
        identify(ref);

        delete ptr;
        std::cout << YELLOW"----------------"RESET << std::endl;
    }
    
}