#include "factorial.hpp"
#include <concepts>

template<unsigned N, unsigned K>
requires (N >= K)
struct C
{
    static constexpr unsigned value = factorial_v<N> / (factorial_v<K> * factorial_v<N - K>);
};

template<unsigned N, unsigned K>
requires (N >= K)
inline constexpr unsigned C_v = C<N, K>::value;
