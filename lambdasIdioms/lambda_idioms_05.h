#pragma once

/*
 * Init capture
 */


#include "../util/print.h"

#include <memory>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace lambda_idioms_05{

struct Widget{};

inline void init_capture(){
    println(__PRETTY_FUNCTION__);

    auto ptr = std::make_unique<Widget>();

    auto f = [ptr = std::move(ptr)]{
        std::cout<<ptr.get()<<"\n";
    };

    assert(ptr == nullptr);

    f();
}


/*
 * Lambda Idiom 5:
 * Init capture optimisation
 */


inline void search_lambda(){
    println(__PRETTY_FUNCTION__);

    const std::vector<std::string> vs = {"apple", "orange", "foobar", "lemon"};
    const std::string prefix = "foo";

  /*  auto result = std::find_if(vs.begin(),vs.end(), [&prefix](auto const& s){
            return s == prefix +"bar";
            });*/
    auto result = std::find_if(vs.begin(), vs.end(), [str = prefix +"bar"](auto const& s){
            return s == str;
            });

    if(result!= vs.end()){
        println(prefix, "-something found");
    }
}


inline void execute(){
    println(__PRETTY_FUNCTION__);

    init_capture();
    search_lambda();
}

}
