#pragma once

#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <condition_variable>

using job_type = std::function<void()>;
class thread_pool
{

public:
    thread_pool( unsigned int num = std::thread::hardware_concurrency() );

    void enqueue_detach( job_type job );
    void wait_for_tasks();
    bool busy();

private:
    void thread_loop();

    bool stop_thread_ {};
    std::mutex mtx_;
    std::condition_variable cv_;
    std::vector<std::thread> threads_;
    std::queue<job_type> jobs_;
};
