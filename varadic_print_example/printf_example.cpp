#include <iostream>
#include <stdexcept>
#include <string>

template<typename T, typename... Args>
void printf( const char * s, T const & value, Args const &... args )
{
    while ( *s ) {
        if ( *s == '%' && *++s != '%' ) {
            std::cout << value;
            printf( ++s, args... );
        }
        std::cout << *s++;
    }
    throw std::runtime_error( "extra arguments provided to printf" );
}

int main()
{

    const char * msg = "The value of %s is about %g (unless you live in %s).\n";
    printf( msg, std::string( "pi" ), 3.14159, "Indian" );
    return 0;
}
