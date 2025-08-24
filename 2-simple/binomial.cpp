#include <iostream>
#include "binomial.hpp"

int main()
{
    std::cout << C_v<5,2> << std::endl; // 10
    std::cout << C_v<5,5> << std::endl; // 1
#if 0 // should not compile
    std::cout << C<5,6>::value << std::endl; // 
#endif
    return 0;
}