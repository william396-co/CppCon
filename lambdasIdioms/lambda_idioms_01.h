#pragma once

#include "../util/print.h"

namespace lambda_idioms_01{

/*
 *  Lambda Idiom 1:
 *  Unary plust trick
 */

inline void legacy_call(int(*f)(int)){
    println(f(7));
}

inline void execute(){
    println(__PRETTY_FUNCTION__);

    // implicitly convert lambda to function pointer
    auto* fptr = +[](int i ){ return i * i;};
    legacy_call(fptr);

    legacy_call([](int i ){return i * i ;});
}


}
