#include "thread_pool.h"

thread_pool::thread_pool( unsigned int num )
{
    for ( unsigned int i = 0; i < num; ++i ) {
        threads_.emplace_back( std::thread( &thread_pool::thread_loop, this ) );
    }
}

void thread_pool::enqueue_detach( job_type job )
{
    {
        std::lock_guard lock( mtx_ );
        jobs_.emplace( std::move( job ) );
    }
    cv_.notify_one();
}

void thread_pool::wait_for_tasks()
{

    {
        std::lock_guard lock( mtx_ );
        stop_thread_ = true;
    }

    cv_.notify_all();
    for ( auto & t : threads_ )
        t.join();

    threads_.clear();
}

void thread_pool::thread_loop()
{
    for ( ;; ) {
        job_type job;
        {
            std::unique_lock lock( mtx_ );
            cv_.wait( lock, [this] { return !jobs_.empty() || stop_thread_; } );

            if ( stop_thread_ )
                break;

            job = std::move( jobs_.front() );
            jobs_.pop();
        }

        // do the job
        job();
    }
}
