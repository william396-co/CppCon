#include <iostream>
#include <string>

class Base
{
public:
    Base()
        : name_ { __FUNCTION__ }
    {
        std::cout << __FUNCTION__ << "\n";
        print1();
    }

    virtual void print1()
    {
        std::cout << __FUNCTION__ << " " << name_ << "\n";
    }

    virtual void print2()
    {
        std::cout << __FUNCTION__ << " " << name_ << "\n";
    }

    virtual ~Base()
    {
        print2();
        std::cout << __FUNCTION__ << " " << name_ << "\n";
    }

protected:
    std::string name_;
};

class Derived : public Base
{
public:
    Derived()
        : Base(), name2_ { __FUNCTION__ }
    {
        std::cout << __FUNCTION__ << "\n";
        print1();
    }

    virtual void print1()
    {
        std::cout << __FUNCTION__ << " " << name2_ << "\n";
    }

    virtual void print2()
    {
        std::cout << __FUNCTION__ << " " << name2_ << "\n";
    }

    virtual ~Derived()
    {
        print2();
        std::cout << __FUNCTION__ << " " << name2_ << "\n";
    }

private:
    std::string name2_;
};

int main()
{

    Base * b = new Derived();
    b->print1();
    b->print2();
    delete b;
    return 0;
}

