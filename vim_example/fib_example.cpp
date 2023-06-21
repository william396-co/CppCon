#include <iostream>
#include <vector>
#include "../util/print.h"

long fibonacci(int n){
	if( n==0 || n == 1)
		return n;
	else 
		return fibonacci(n-1)+fibonacci(n-2);
}

long fib(int n)
{
    if(n ==0 || n ==1)
    {
        return n;
    }
    std::vector<long> fibs(n+1);
    fibs[0]= 0;
    fibs[1]= 1;
    for(int i =1; i <=n;++i){
        fibs[i] = fibs[i-1]+fibs[i-2];
    }
    return fibs[n];
}

int main(){
    std::cout<<"hello "<<std::endl;
    for(int i =0; i < 10;++i){
	    std::cout<<"fibonacci("<<i<<")="<< fibonacci(i)<<"\n";
    }

    for(int i=0;i < 100;++i){
        println("fib(",i,")=",fib(i));
    }
    return 0;
}
