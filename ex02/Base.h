#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Base {
public:
    virtual ~Base();
};

class A: public Base {
};

class B: public Base {
};

class C: public Base {
};

Base *generate(void);

void identify(Base*);
void identify(Base&);