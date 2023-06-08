#include <any>
#include <functional>
#include <unordered_map>
#include <string>

#include "../util/print.h"

// reference link https://www.appsloveworld.com/cplus/100/30/store-functions-with-different-signatures-in-a-map
template<typename Ret>
struct AnyCallable
{
    AnyCallable(){}

    template<typename F>
    AnyCallable(F&& fn): AnyCallable(std::function(std::forward<F>(fn))){}

    template<typename...Args>
        AnyCallable(std::function<Ret(Args...)> fn):m_any(fn){}

    template<typename...Args>
    Ret operator()(Args&&...args)
    {
        return std::invoke(std::any_cast<std::function<Ret(Args...)>>(m_any), std::forward<Args>(args)...);
    }

    std::any m_any;
};

using FuncMap = std::unordered_map<std::string, AnyCallable<void>>;

void foo(int x, int y)
{
    println(__PRETTY_FUNCTION__,"(",x,",",y,")");
}

void bar(std::string const& str, int x, int y, int z)
{
    println(__PRETTY_FUNCTION__,"(",str,",",x,",",y,",",z,")");
}

template<typename...Args>
void exe(FuncMap& funcMap,std::string const& func,Args&&...args)
{
    auto it = funcMap.find(func);
    if(it != funcMap.end()){
        it->second(std::forward<Args>(args)...);
    }
}


int main()
{
    FuncMap fmp;
//    fmp["foo"] = &foo;
  //  fmp["bar"] = &bar;
    fmp.emplace("bar",bar);
    fmp.emplace("foo",foo);

    fmp["foo"](1,2);
    fmp["bar"].operator()<std::string const&,int,int,int>("good bar",1,2,3);

    exe(fmp,"bar",std::string("good bar"),11,22,33);
    //exe(fmp, "bar", 1,2);
    exe(fmp, "bar","bar",1,2); // bad_any_cast beca

    return 0;
}
