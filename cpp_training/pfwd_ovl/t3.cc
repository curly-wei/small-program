#include <iostream>
long multiply(int i, int j) { std::cout << "func" << std::endl ;return i * j; }

template <class T>
typename T::multiplication_result multiply(T t1, T t2)
{
    std::cout << "tmp" << std::endl ;
    return t1 * t2;
}

int main(void)
{
    std::cout << multiply(4, 5) << std::endl; 
}
