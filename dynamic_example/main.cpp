#include "../util/print.h"


class Base
{
public:
    virtual ~Base(){
        println(__PRETTY_FUNCTION__);
    }

    virtual void test1()
    {
        println(__PRETTY_FUNCTION__);
    }

    void test2()
    {
        println(__PRETTY_FUNCTION__);
    }
};

class Derived: public Base
{
public:
    virtual ~Derived(){
        println(__PRETTY_FUNCTION__);
    }
   
    virtual void test1() override{
        println(__PRETTY_FUNCTION__);
    }

};

int main()
{
    Derived d;
    d.test1();
    d.test2();
    
    return 0;
}
