#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include <sys/mman.h>

#define THREAD_SIZE 10

int count = 0;
pthread_mutex_t mutex;
pthread_spinlock_t spinlock;
pthread_rwlock_t rwlock;

// MOV dest , src  AT&T
// MOV src,  dest   x86

int inc( int * value, int add )
{
    int old;

    __asm__ volatile ( 
        "lock; xaddl %2, %1;" // "lock; xchg %2, %1, %3;" 
        : "=a" (old)
        : "m" (*value), "a" (add)
        : "cc", "memory"
    );  
    return old;
}

void * func( void * arg )
{
    int * pcount = (int *)arg;

    int i = 0;
    while ( i++ < 100000 ) {

        //  ( *pcount )++;
        inc( pcount, 1 );
        usleep( 1 );
    }
}

int main()
{

    pthread_t threadid[THREAD_SIZE] = { 0 };

    pthread_mutex_init( &mutex, NULL );
    pthread_spin_init( &spinlock, PTHREAD_PROCESS_SHARED );
    pthread_rwlock_init( &rwlock, NULL );

    int count = 0;
    for ( int i = 0; i < THREAD_SIZE; ++i ) {
        int ret = pthread_create( &threadid[i], NULL, func, &count );
        if ( ret ) {
            break;
        }
    }

    for ( int i = 0; i < 100; ++i ) {
        pthread_rwlock_rdlock( &rwlock );
        printf( "count--> %d\n", count );
        pthread_rwlock_unlock( &rwlock );

        sleep( 1 );
    }

    return 0;
}
