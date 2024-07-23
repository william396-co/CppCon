#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include <iostream>

void sig_handler( int signo )
{
    std::cout << "recieve signal: " << signo << "\n";
}

int main()
{

    signal( SIGALRM, sig_handler );

    struct itimerval timer_set;

    // start timer (after 5 second)
    timer_set.it_value.tv_sec = 5;
    timer_set.it_value.tv_usec = 0;

    // interval 2 second
    timer_set.it_interval.tv_sec = 2;
    timer_set.it_interval.tv_usec = 0;

    if ( setitimer( ITIMER_REAL, &timer_set, NULL ) < 0 ) {
        std::cout << "start timer failed...\n";
        return 0;
    }

    int temp;
    std::cin >> temp;

    return 0;
}
