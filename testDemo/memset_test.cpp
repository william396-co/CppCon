#include <iostream>
#include <cstring>

class Base
{
public:
    Base( int a )
        : a { a } {}
    virtual ~Base() {}
    virtual void fuck()
    {
        //  std::cout << "sizeof(Derived)=" << sizeof( Derived ) << " sizeof(Base)=" << sizeof( Base ) << "\n";
        memset( this, 0, sizeof( *this ) );
    }

    virtual void output()
    {
        std::cout << __PRETTY_FUNCTION__ << " a = " << a << "\n";
    }
    int a;
};

class Derived : public Base
{
public:
    Derived( int a, int b )
        : Base { a }, b { b } {}

    void fuck() override
    {
        //  std::cout << "sizeof(Derived)=" << sizeof( Derived ) << " sizeof(Base)=" << sizeof( Base ) << "\n";
        memset( this, 0, sizeof( *this ) );
    }
    void output() override
    {
        Base::output();
        std::cout << __PRETTY_FUNCTION__ << " b = " << b << "\n";
    }

    int b;
};

int main()
{

    Base * d = new Derived { 1, 2 };
    //  std::cout << d.a << " " << d.b << "\n";
    d->output();

    d->fuck();

    // std::cout << d.a << " " << d.b << "\n";
    d->output();

    return 0;
}
