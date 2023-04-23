#pragma once

#include "../util/print.h"

#include <vector>
#include <functional>
/*
 * Lambda Idiom 2:
 * Immediately Invoked Function Expressions(IIFE)
 */

struct Foo{};

Foo getFooFromDataBase(){
    return Foo{};
}

Foo getFooFromElseWhere(){
    return Foo{};
}


namespace lambda_idioms_02
{

inline void execute(){
    println(__PRETTY_FUNCTION__);

    []{ println("Hello, World"); }(); // IIFE


    bool hasDataBase = false;
    const Foo foo  = [&]{
        if(hasDataBase)
            return getFooFromDataBase();
        else
            return getFooFromElseWhere();
    }();


    std::vector<Foo> foos;

    foos.emplace_back([&] {
               if(hasDataBase)
                    return getFooFromDataBase();
                else
                    return getFooFromElseWhere();
            }());
    foos.emplace_back( std::invoke([&] {
               if(hasDataBase)
                    return getFooFromDataBase();
                else
                    return getFooFromElseWhere();
            }));
}

}
