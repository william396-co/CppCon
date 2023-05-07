#pragma once

/*
 * Lambda Idiom 3:
 * Call-once Lambda
 */

#include "../util/print.h"

namespace lambda_idioms_03
{

struct X{

    X(){ // local static unamed(just use _ as a name) lambda
    static auto _ = []{  println("call once!"); return 0;}();
    }
};

inline void execute(){
    println(__PRETTY_FUNCTION__);

    X x1;
    X x2;
    X x3;
}
}
