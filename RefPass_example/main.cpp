#include "../util/print.h"

#include <string>

class Ref
{
public:
    Ref( int id )
        : id_ { id } {}

    int & getId() { return id_; }

private:
    int id_;
};

void pass_ref_test(int& ref){
    ref = 100;
}

int main()
{

    Ref ref{3};
    ref.getId()= 5;
    println(ref.getId());

    pass_ref_test(ref.getId());
    println(ref.getId());
    return 0;
}
