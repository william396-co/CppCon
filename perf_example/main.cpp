#include <cstdio>
#include <vector>
#include <cstddef>

long long fib( int n )
{
    std::vector<long long> dp( n + 1, 0 );
    dp[0] = 0;
    dp[1] = 1;
    for ( size_t i = 2; i < dp.size(); ++i ) {
        dp[i] = dp[i - 1] + dp[i - 1];
    }
    return dp[n - 1];
    /*
    if ( n <= 1 )
        return n;
    return fib( n - 1 ) + fib( n - 2 );*/
}
void funcA( int n )
{
    printf( "%s\n", __FUNCTION__ );

    for ( int i = 0; i < n; ++i ) {
        printf( "fib(%d)=%ld\n", i, fib( i ) );
    }
}
void funcB( int n )
{
    printf( "%s\n", __FUNCTION__ );

    for ( int i = 0; i < n; ++i ) {
        printf( "fib(%d)=%ld\n", i, fib( i ) );
    }
}
void funcC( int n )
{
    printf( "%s\n", __FUNCTION__ );

    for ( int i = 0; i < n; ++i ) {
        printf( "fib(%d)=%ld\n", i, fib( i ) );
    }
}

int main()
{

    for ( int i = 0; i < 100; ++i ) {
        if ( i < 10 )
            funcA( i );
        else if ( i < 36 )
            funcB( i );
        else
            funcC( i );
    }

    return 0;
}
