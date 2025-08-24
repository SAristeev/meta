#include "factorial.hpp"

template <unsigned alpha, unsigned beta, unsigned gamma>
struct monomial_3d
{
    static constexpr unsigned value =
        factorial_v<alpha + beta + gamma + 3> / 
        (
            factorial_v<alpha> * factorial_v<beta> * factorial_v<gamma>
        );
};

template <unsigned alpha, unsigned beta, unsigned gamma>
inline constexpr unsigned monomial_3d_v = monomial_3d<alpha, beta, gamma>::value;