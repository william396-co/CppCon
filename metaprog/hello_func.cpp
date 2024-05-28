#include <iostream>

template<typename T>
struct Fun_
{
    using type = T;
};

template<int>
struct Fun_
{
    using type = unsigned int;
}

template<long>
struct Fun_
{
    using type = unsigned long;
}

template<typename T>
using Fun = typename Fun_<T>::type;

int main()
{

    Fun<int> h1 = 2;

    Fun_<int> h2 = 3;
    std::cout << h1 << " " << h2 << "\n";

    return 0;
}
