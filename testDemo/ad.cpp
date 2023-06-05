#include <cstdio>
#include <vector>
#include <cstdlib>

int main()
{
    printf( "location of main:%p\n", (void *)main );
    int x = 1;
    std::vector<int> a( 1, 0 );
    printf( "loca of x:%p\n", &x );
    printf( "local of &a: %p\n", &a );
    printf( "local of a:%p\n", a );
    printf( "local of a.data= %p\n", &a[0] );
    printf( " local of stack: %p\n", (void *)malloc( 1 ) );

    return 0;
}
