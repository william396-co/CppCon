#include <iostream>

struct A
{
    int c : 3;
};

int main()
{
    A a1;
    a1.c = 3;

    std::cout << a1.c << "\n";
    a1.c++;

    std::cout << a1.c << "\n";
    return 0;
}
