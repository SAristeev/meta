#include <iostream>
#include <concepts>


#if 0 // runtime
double pow(double x, int N)
{
    if (N < 0)
    {
        return 1 / pow(x, -N);
    }
    else if (N == 0)
    {
        return 1;
    }
    else if(N % 2 ==0)
    {
        double p = pow(x, N / 2);
        return p * p;
    }
    else 
    {
        return x * pow(x, N - 1);
    }
}
#endif

#if 0 // bad practice
template<int N, typename T>
requires (N < 0)
constexpr T pow(T x) { return 1 / pow<-N>(x);}

template<int N, typename T>
requires (N == 0)
constexpr T pow(T x) { return 1; }

template<int N, typename T>
requires (N > 0) && (N % 2 == 0)
constexpr T pow(T x) { T p = pow<N / 2>(x); return p * p; }

template<int N, typename T>
requires (N > 0) && (N % 2 != 0)
constexpr T pow(T x) { T p = pow<N - 1>(x); return x * p; }
#endif

template<int N, typename T>
constexpr T pow(T x) 
{ 
    if constexpr (N < 0) {
        return T(1) / pow<-N>(x);
    } else if constexpr (N == 0) {
        return T(1);
    } else if constexpr (N % 2 == 0) {
        T p = pow<N / 2>(x);
        return p * p;
    } else {
        return pow<N - 1>(x) * x;
    }
}
int main()
{
    std::cout << pow<-1>(2.0) << std::endl;
    std::cout << pow<0>(2.0) << std::endl;
    std::cout << pow<1>(2.0) << std::endl;
    std::cout << pow<2>(2.0) << std::endl;
    std::cout << pow<3>(2.0) << std::endl;
    std::cout << pow<4>(2.0) << std::endl;
}