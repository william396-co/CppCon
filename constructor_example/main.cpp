#include "../util/print.h"


class X{
    int i = 3;
public:
    X(int val){
        i = val;
        println("i = ", i);
    }
};

class Y: public X
{
    int j = 1;
public:
    int getj(){return j;}
    Y(int val):X(getj()),j(val)
    {
        println("j = ",j);
    }
};
int main()
{
   Y y(2);
    return 0;
}
