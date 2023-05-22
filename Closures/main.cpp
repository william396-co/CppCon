#include <functional>
#include <map>

#include "../util/print.h"


int newCounter()
{
    int count = 0;
    return [count]() mutable{ return ++count;}();
}


int main()
{

    std::map<int, std::function<int()>> fun_map;
    fun_map.emplace(1,newCounter);
    fun_map.emplace(2,newCounter);

    auto f1 = fun_map[1];
    auto f2 = fun_map[2];

    for(auto& it: fun_map)
    {
        println(it.first, " execute = ", it.second());
    }

    println(f1());
    println(f2());
    println(f1());
    println(f1());

    return 0;
}
