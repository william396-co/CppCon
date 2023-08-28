#include <iostream>
using namespace std;
#include "threadpool.hpp"
#include <functional>
#include <chrono>
#include <string>

#include <random>
std::random_device rd;                                  // 真实的随机产生器

std::mt19937 mt( rd() );                                // 生成计算随机数mt;

std::uniform_int_distribution<int> dist( -1000, 1000 ); // 生成 - 1000到1000之间的离散均匀分部数
auto rnd = std::bind( dist, mt );

// std::mutex cout_mtx;
// void cout_put(const string& str)
//{
//	lock_guard<mutex> lock(cout_mtx);
//	cout << str << "\n";
// }

void simulate_hard_computation()
{
    std::this_thread::sleep_for( std::chrono::nanoseconds( 1000 + rnd() ) );
}

void multipy( int a, int b )
{
    simulate_hard_computation();
    int res = a * b;
    printf( "multipy:\t%d*%d=%d\n", a, b, res );
}

void multiply_output( int & out, int a, int b )
{
    simulate_hard_computation();
    out = a * b;
    printf( "multiply_output:\t%d*%d=%d\n", a, b, out );
}

int multiply_return( int a, int b )
{
    simulate_hard_computation();
    int res = a * b;
    printf( "multiply_return:\t%d*%d=%d\n", a, b, res );
    return res;
}

void example()
{
    ThreadPool pool( 3 );
    pool.init();

    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 10; ++j )
            pool.submit( multipy, i, j );
    }
    // 使用ref传递的输出参数提交函数
    int output_ref;
    auto future1 = pool.submit( multiply_output, std::ref( output_ref ), 5, 6 );
    // 等待乘法输出完成
    future1.get();
    printf( "Last operation result is equal to %d\n", output_ref );

    // 使用return 参数提交函数
    auto future2 = pool.submit( multiply_return, 5, 3 );
    int res = future2.get();
    printf( "Last operation result is equal to %d\n", res );

    pool.shutdown();
}

int main()
{
    example();

    printf( "ThreadPool Demo\n" );

    return 0;
}
