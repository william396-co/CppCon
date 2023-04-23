#pragma once

/*
 * C++14 generic lambda
 *
 */

#include "../util/print.h"
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>
#include <variant>

using ms = std::chrono::milliseconds;
using us = std::chrono::microseconds;
using ns = std::chrono::nanoseconds;


struct Time
{
    Time(ns ns_time): time{ns_time}{}
    Time(ms ms_time): time{ms_time}{}
    std::variant<ms,ns> time;

    auto convert(auto const& converter){
        return std::visit(converter, time);
    }
};


template<typename T>
constexpr auto duration_cast = [](auto d){
    return std::chrono::duration_cast<T>(d);
};

namespace lambda_idioms_04
{

inline void generic_lambda_test(){
    println(__PRETTY_FUNCTION__);

    std::map<int,std::string> httpErors{
        {400,"Bad Request"},
        {401,"Unauthorised"},
        {402,"Forbidden"},
        {404,"Not Found"}
    };

    std::for_each(httpErors.begin(), httpErors.end(),
            [](auto const& item){ // generic lambda
                println(item.first ,":", item.second);
            });
}


inline void normal_generic_lambda()
{
    println(__PRETTY_FUNCTION__);

    // generic lambda just the call operator is template function
    auto generic_call = [](auto i){
        println(i);
    };

    generic_call("hello generic lambda");
    generic_call(123467);
    generic_call(3.14159626f);
}

inline void forward_lambda(){
    println(__PRETTY_FUNCTION__);

    std::vector<std::string> v;
    auto f =[&v](auto&&item){
        v.push_back(std::forward<decltype(item)>(item));
    };

    f("hello");
    f("morning");

    print_con(v);
}

inline void variadic_template_lambda(){
    println(__PRETTY_FUNCTION__);

    auto f = [](auto&&...args){
        (std::cout<<...<<args);
    };
    f("hello", 42, 1.4);
}


inline void lambda_call_lambda(){
    println(__PRETTY_FUNCTION__);

    auto twice = [](auto&&f){
        return [=]{ f(); f();};
    };

    auto print_hihi = twice([]{ println("hi"); });

    print_hihi();
}

/*
 * lambda Idiom 4:
 * Variable template lambda
 */

template<typename T>
constexpr auto c_cast = [](auto x){
    return (T)x;
};

inline void time_lambda(){
    println(__PRETTY_FUNCTION__);

    Time t(ns(30000));
    println(t.convert(duration_cast<us>).count());


//    println(t.convert(std::chrono::duration_cast<us>).count()); //Error
}


inline void execute(){
    println(__PRETTY_FUNCTION__);

    generic_lambda_test();

    normal_generic_lambda();

    forward_lambda();

    variadic_template_lambda();

    lambda_call_lambda();

    println(c_cast<int>(3.14159));

    time_lambda();

}
}
