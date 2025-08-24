#include <iostream>
#include "factorial.hpp"

int main()
{
    std::cout << factorial<5>::value << std::endl; // 120
    return 0;
}