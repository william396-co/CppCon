#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{

    /* 创建套接字 */
    if ( ( listen_sock = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP ) ) < 0 ) {
        perror( "socket()" );
        exit( EXIT_FAILURE );
    }

    /* 检查 keepalive 选项的状态  */
    if ( getsockopt( listen_sock, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen ) < 0 ) {
        perror( "getsockopt()" );
        close( listen_sock );
        exit( EXIT_FAILURE );
    }
    printf( "SO_KEEPALIVE default is %s\n", ( optval ? "ON" : "OFF" ) );

    /* 将选项设置为活动  */
    optval = 1;
    optlen = sizeof( optval );

    if ( setsockopt( listen_sock, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen ) < 0 ) {
        perror( "setsockopt()" );
        close( listen_sock );
        exit( EXIT_FAILURE );
    }
    printf( "SO_KEEPALIVE set on socket\n" );

    /* 再次检查状态  */
    if ( getsockopt( listen_sock, IPPROTO_TCP, TCP_KEEPIDLE, &optval, &optlen ) < 0 ) {
        perror( "getsockopt()" );
        close( listen_sock );
        exit( EXIT_FAILURE );
    }
    printf( "TCP_KEEPIDLE is %d\n", optval );
    /* 再次检查状态  */
    if ( getsockopt( listen_sock, IPPROTO_TCP, TCP_KEEPCNT, &optval, &optlen ) < 0 ) {
        perror( "getsockopt()" );
        close( listen_sock );
        exit( EXIT_FAILURE );
    }
    printf( "TCP_KEEPCNT is %d\n", optval );
    /* 再次检查状态  */
    if ( getsockopt( listen_sock, IPPROTO_TCP, TCP_KEEPINTVL, &optval, &optlen ) < 0 ) {
        perror( "getsockopt()" );
        close( listen_sock );
        exit( EXIT_FAILURE );
    }
    printf( "TCP_KEEPINTVL is %d\n", optval );
    /* 初始化套接字结构 */
    bzero( (char *)&serv_addr, sizeof( serv_addr ) );
    int portno = atoi( argv[1] );
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( portno );

    ...
}
