#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <cmath>

int fixdouble( double f )
{
    int d = f;
    double a = std::abs( f - (double)d );
    return a > 0.99999 ? d + 1 : d;
}

int main()
{
    double d = 475.99999999999997d;
    printf( "d=%.16f  i = %ld\n", d, (int)d );     // 476.00 475
    printf( "d=%.16f  i = %ld\n", d, (int64_t)d ); // 476.00 475

    float f = d;
    printf( "d=%.16f  i = %ld\n", d, (int)f );                    // 476.00 476
    printf( "d=%.16f  i = %ld\n", d, static_cast<int64_t>( f ) ); // 476.00 476

    printf( "d=%.16f  i = %ld\n", d, fixdouble( d ) );     // 476.00 475
    printf( "d=%.16f  i = %ld\n", d, (int64_t)std::ceil( d ) ); // 476.00 475

    return 0;
}
