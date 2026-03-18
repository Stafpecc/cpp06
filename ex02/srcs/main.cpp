#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base* obj = generate();

        std::cout << "Pointer identify: ";
        identify(obj);

        std::cout << "Reference identify: ";
        identify(*obj);

        delete obj;
        std::cout << "----" << std::endl;
    }

    return 0;
}