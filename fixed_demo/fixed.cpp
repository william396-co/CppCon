#include <iostream>
#include <iomanip>
#include "fixed.hpp"

#include <sstream>

template<typename T>
std::string to_string_with_precision( const T a_value, const int n = 4 )
{
    std::ostringstream out;
    out.precision( n );
    out << std::fixed << a_value;
    return out.str();
}

int main()
{

    using fixed64 = fpm::fixed<int64_t, int64_t, 14>;

    {

        std::cout << " float data example \n";
        auto fp1 = fixed64( 1.234f );
        auto fp2 = fixed64( 0.234f );

        std::cout << "fp1=" << to_string_with_precision( (float)fp1 ) << "\tfp2= " << to_string_with_precision( (float)fp2 ) << "\n";

        std::cout << "fp1-fp2= " << to_string_with_precision( float( fp1 - fp2 ) ) << "\n";
        std::cout << "fp1+-fp2= " << to_string_with_precision( float( fp1 + fp2 ) ) << "\n";
        std::cout << "fp1*fp2= " << to_string_with_precision( float( fp1 * fp2 ) ) << "\n";
        std::cout << "fp1/fp2= " << to_string_with_precision( float( fp1 / fp2 ) ) << "\n";
    }

    {
        std::cout << " double data example \n";

        auto fp1 = fixed64( 1.234d );
        auto fp2 = fixed64( 0.234d );

        std::cout << "fp1=" << to_string_with_precision( (double)fp1 ) << "\tfp2= " << to_string_with_precision( (double)fp2 ) << "\n";

        std::cout << "fp1-fp2= " << to_string_with_precision( double( fp1 - fp2 ) ) << "\n";
        std::cout << "fp1+-fp2= " << to_string_with_precision( double( fp1 + fp2 ) ) << "\n";
        std::cout << "fp1*fp2= " << to_string_with_precision( double( fp1 * fp2 ) ) << "\n";
        std::cout << "fp1/fp2= " << to_string_with_precision( double( fp1 / fp2 ) ) << "\n";
    }

    return 0;
}
