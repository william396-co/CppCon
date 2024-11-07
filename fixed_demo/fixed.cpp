#include <iostream>
#include <iomanip>
#include <cstdio>
#include "fixed.hpp"

#include <sstream>

template<typename T>
std::string to_string_with_precision( const T a_value, const int n = 8 )
{
    std::ostringstream out;
    out.precision( n );
    out << std::fixed << a_value;
    return out.str();
}

using byte_pointer = char *;

void show_bytes( byte_pointer start, size_t len )
{
    for ( size_t i = 0; i != len; ++i ) {
        if ( 0 == i ) {
            printf( "%.2x", start[i] );
        } else {
            printf( " %.2x", start[i] );
        }
    }
    printf( "\n" );
}

void show_details( double f )
{
    using fixed64 = fpm::fixed<int64_t, int64_t, 13>; // prcesion to 0.0001 13bit is enough

    fixed64 fp = fixed64( f );
    auto rf = fp.raw_value();
    show_bytes( (byte_pointer)&rf, sizeof( rf ) );

    std::cout << "f = " << f << "\tfp=" << to_string_with_precision( (double)fp ) << "\n";
}

int main()
{

    using fixed64 = fpm::fixed<int64_t, int64_t, 14>;

    {

        std::cout << "============= fixed64 use 4 bits store fraction===========\n";
        using fixed64 = fpm::fixed<int64_t, int64_t, 4>;
        fixed64 min = fixed64::from_raw_value( 0x0000000000000011 ); // 1/16

        fixed64 max = fixed64::from_raw_value( 0x000000000000001f ); // 15/16

        std::cout << "min = " << to_string_with_precision( (double)min ) << " max = " << to_string_with_precision( (double)max ) << "\n";
    }
    {
        std::cout << "==================fixed64 use 4 bits store fraction show fixedpoint details===========\n";

        show_details( 1.0001d ); // 0x00000012 1.125
        show_details( 1.0002d ); // 0x00000013 1.1875
        show_details( 1.0004d ); // 0x00000012 1.125
        show_details( 1.0005d );
        show_details( 1.0006d );
        show_details( 1.0007d );
    }

    {

        std::cout << "=============fixed64 use 8 bits store fraction===========\n";

        using fixed64 = fpm::fixed<int64_t, int64_t, 8>;
        fixed64 min = fixed64::from_raw_value( 0x0000000000000101 );

        fixed64 max = fixed64::from_raw_value( 0x000000000000001f );

        std::cout << "min = " << to_string_with_precision( (double)min ) << " max = " << to_string_with_precision( (double)max ) << "\n";
    }
    {

        std::cout << "\n================ float data example ===================\n";
        auto fp1 = fixed64( 1.234f );
        auto fp2 = fixed64( 0.234f );

        std::cout << "fp1=" << to_string_with_precision( (float)fp1 ) << "\tfp2= " << to_string_with_precision( (float)fp2 ) << "\n";

        std::cout << "fp1-fp2= " << to_string_with_precision( float( fp1 - fp2 ) ) << "\n";
        std::cout << "fp1+fp2= " << to_string_with_precision( float( fp1 + fp2 ) ) << "\n";
        std::cout << "fp1*fp2= " << to_string_with_precision( float( fp1 * fp2 ) ) << "\n";
        std::cout << "fp1/fp2= " << to_string_with_precision( float( fp1 / fp2 ) ) << "\n";
    }

    {
        std::cout << "\n====== double data example ==============\n";

        auto fp1 = fixed64( 1.234d );
        auto fp2 = fixed64( 0.234d );

        std::cout << "fp1=" << to_string_with_precision( (double)fp1 ) << "\tfp2= " << to_string_with_precision( (double)fp2 ) << "\n";

        std::cout << "fp1-fp2= " << to_string_with_precision( double( fp1 - fp2 ) ) << "\n";
        std::cout << "fp1+fp2= " << to_string_with_precision( double( fp1 + fp2 ) ) << "\n";
        std::cout << "fp1*fp2= " << to_string_with_precision( double( fp1 * fp2 ) ) << "\n";
        std::cout << "fp1/fp2= " << to_string_with_precision( double( fp1 / fp2 ) ) << "\n";
    }

    return 0;
}
