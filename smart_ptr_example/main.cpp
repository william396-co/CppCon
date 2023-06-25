#include <memory>
#include <string>

#include "../util/print.h"

class A
{
public:
    explicit A(std::string const& name):m_name{name}{
        println(__PRETTY_FUNCTION__,"(",m_name,")");
    }

    void close()
    {
        println(m_name," " , __PRETTY_FUNCTION__);
    }

    ~A(){
         println(__PRETTY_FUNCTION__,"(",m_name,")");
    }

private:
    std::string m_name;
};


int main()
{
    
    std::unique_ptr<A,void(*)(A*)> pa (new A("a string"),[](A* ptr){
                                       ptr->close();delete ptr;});

        
    return 0;
}
