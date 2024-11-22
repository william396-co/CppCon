#include "thread_pool.h"

#include <iostream>

int main()
{

    thread_pool pool;
    for ( int i = 0; i != 10000; ++i ) {
        pool.enqueue_detach( [i]() {
            std::cout << "this " << i << "\n";
        } );
    }
    pool.wait_for_tasks();
    return 0;
}
