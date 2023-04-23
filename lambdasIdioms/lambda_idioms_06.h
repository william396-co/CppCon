#pragma once

/*
 * Class template argument deduction(CTAD)
 *
 * Lambda Idiom 6:
 * Lambda overload set
 */

#include "../util/print.h"

#include <variant>
#include <iostream>
#include <vector>
#include <algorithm>

namespace lambda_idioms_06
{

// C++17
template<typename...Ts>
struct overload: public Ts...{
    using Ts::operator()...;
};

inline void overload_lambda(){
    println(__PRETTY_FUNCTION__);

    overload f = {
        [](int i){ println("int thingy"); },
        [](float f){ println("float thingy"); }
    };

    std::variant<int, float> v = 42;
    std::visit(f,v);

    f(2);
    f(2.0f);
}

// C++20
#if __cplusplus > 201703L

struct Widget{
    float x,y;

    auto f = []{}; //error


    decltype([]{}) f;
};

inline void template_lambda(){
    println(__PRETTY_FUNCTION__);

    auto [x,y] = Widget();
    auto f = [=]{
        println(x, ",", y);
    };

    std::vector<int> data = {1,2,3,4,5};
    std::erase_if(data, [](auto i){ return i % 2;});// generic lambda

    // template lambda
    std::erase_if(data, []<typename T>(T i) {
            return i % 3;
            });
}


template<typename T>
auto  myDeleter(T *t){
    delete t;
}

template<typename T>
using MyPtr = std::unique_ptr<T,decltype([](T*t){ myDeleter(t);})>;

MyPtr<Widget> ptr;

using WidgetSet = std::set<Widget, decltype([](Widget const& lhs, Widget const& rsh){return lhs.x < rhs.x;})>;
WidgetSet widgets;

#endif

#if __cplusplus > 201703L
template<auto =[]{}>
struct X{};


#endif
// Every new lambda expression generate a new closure type！
inline void lambda_type(){
    println(__PRETTY_FUNCTION__);

    auto f1 = []{};
    auto f2 = []{};
// f1 and f2 have different type

    auto f3 = f1; // f1 and f3 have same type
                  //
#if __cplusplus > 201703L

    delctype(f1) f4; // f1 and f4 have same type
                     //
    using t = delctype([]{});
    t f5;
    t f6; //f5 and f6 have same type

    decltype([]{}) f7;
    delctype([]{}) f8; // f7 and f8 have different type

    X x1;
    X x2; // x1 and x2 have different types,  every time insantiation, so lambda everytime is new
#endif
}


inline void execute(){
    println(__PRETTY_FUNCTION__);

    std::vector vi = {1,2,3,4,5,6}; //deduc to std::vector<int>
    print_con(vi);

    overload_lambda();

}
}
