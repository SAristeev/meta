#include "factorial.hpp"
#include <concepts>

template<unsigned N, unsigned K>
requires (N >= K)
struct C
{
    static constexpr unsigned value = factorial<N>::value / (factorial<K>::value * factorial<N - K>::value);
};