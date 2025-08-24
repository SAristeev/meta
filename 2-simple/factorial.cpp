#include <iostream>

template<unsigned N>
struct factorial
{
    static constexpr unsigned value = N * factorial<N - 1>::value;
};

template<>
struct factorial<0>
{
    static constexpr unsigned value = 1;
};

int main()
{
    std::cout << factorial<5>::value << std::endl; // 120
    return 0;
}