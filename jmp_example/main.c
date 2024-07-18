#include <stdio.h>
#include <assert.h>
#include <setjmp.h>

jmp_buf b;

#define TRY if ( setjmp( b ) == 0 )
#define CATCH else
#define THROW( b ) longjmp( b, 1 )

void foo()
{
    printf( "foo\n" );
    THROW( b );
}

int main()
{

    TRY
    {
        foo();
    }
    CATCH
    {
        printf( "catch!\n" );
    }

    return 0;

    {

        int ret = setjmp( b );
        printf( "setjmp result = %d\n", ret );

        if ( ret == 0 ) {
            longjmp( b, 1 );
        }
    }
    return 0;
}
