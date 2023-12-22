#include <iostream>

class Test
{
public:
    void print()
    {
        i;
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    virtual void println()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
private:
    int i{};
};

int main()
{
    //
    {
        Test * t = nullptr;
        t->print();   // ok,like call print(this) ,this not deref
        t->println(); // segement fault ,this->[0]()println(this)
    }

    return 0;
}
