#include <cstring>
#include <iostream>

int main()
{

#define PAUSE( msg )               \
    std::cout << msg << std::endl; \
    std::cin >> p

    char p;

    size_t size = 1024 * 1024 * 100;

    char * l = new char[size];

    PAUSE( "new" );

    memset( l, 1, size / 2 );
    PAUSE( "Using half large" );

    memset( l, 1, size );
    PAUSE( "using whole large" );

    delete[] l;
    PAUSE( "del" );

    return 0;
}
