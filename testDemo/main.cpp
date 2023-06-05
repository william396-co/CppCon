#include <iostream>
#include <typeinfo>
#include <type_traits>

/*
template<typename T>
class is_class
{
    typedef char yes[1];
    typedef char no[2];

    template<typename C>
    static yes & test( int C::* ); // selected if C is a class type

    template<typename C>
    static no & test( ... ); // selected otherwise

public:
    static bool const value = sizeof( test<T>( 0 ) ) == sizeof( yes );
};
*/
union UA
{
};

struct MyStruct
{
    int myInt;
};
class MyClass
{
public:
    MyClass() {}
    void doSomething() {}
};

struct Stu : public MyClass
{
};

struct A
{};
union B
{};

int main()
{
    std::cout << std::boolalpha;                              // 输出 bool类型值，而不是数字1或0
    std::cout << std::is_class<MyStruct>::value << std::endl; // 输出 false
    std::cout << std::is_class<MyClass>::value << std::endl;  // 输出 true
    std::cout << std::is_class<Stu>::value << std::endl;      // 输出 true

    std::cout << std::is_class<UA>::value << std::endl; // 输出 true

    std::cout << " sizeof(A) =" << sizeof( A ) << " sizeof(B) = " << sizeof( B ) << "\n";
    std::cout << "A is union :" << std::is_union<A>::value << " B is union: " << std::is_union<B>::value << "\n";

    std::cout << std::is_union<bool>::value << "\n";

    std::cout << typeid( MyClass ).name() << " " << typeid( MyStruct ).name() << "\n";

    return 0;
}
