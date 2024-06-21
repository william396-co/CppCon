#include <iostream>

class X
{
public:
    X( int i )
        : i { i }, j { 0 } {}

    X( int i, int j )
        : i { i }, j { j } {}
    void print()
    {
        std::cout << "i = " << i << " j = " << j << "\n";
    }

private:
    int i;
    int j;
};

int main()
{

    // 隐式转换 从int->X 调用的X(int)
    X x = 2;
    x.print();

    // 显示构造
    X x1 = X { 3 };
    x1.print();

    X x2 = { 2, 3 };
    x2.print();

    return 0;
}
