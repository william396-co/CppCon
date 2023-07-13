#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define UDP_TEST_PORT 50001
#define UDP_SERVER_IP "127.0.0.1"

void getsockname( int fd, struct sockaddr_in * addr )
{
    socklen_t addr_len = sizeof( *addr );
    if ( getsockname( fd, (struct sockaddr *)addr, &addr_len ) == -1 ) {
        perror( "getsockname failed\n" );
        return;
    }

    //    printf( "fd: %d [%s:%d]\n", fd, inet_ntoa( addr->sin_addr ), ntohs( addr->sin_port ) );
}

int main( int argC, char * arg[] )
{
    int sockfd, len = 0;
    socklen_t addr_len = sizeof( struct sockaddr_in );
    char buffer[256];

    /* 建立socket，注意必须是SOCK_DGRAM */
    if ( ( sockfd = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP ) ) < 0 ) {
        perror( "socket" );
        exit( 1 );
    }

    struct sockaddr_in localaddr;
    //localaddr.sin_port = htons( 9527 );
    if ( bind( sockfd, (struct sockaddr *)&localaddr, addr_len ) < 0 ) {
        perror( "bind failed" );
        exit( 2 );
    }

    // 获得bind后系统分配的本地端口
    print_getsockname( sockfd, &localaddr );

    /* 填写sockaddr_in*/
    struct sockaddr_in remoteaddr;
    bzero( &remoteaddr, sizeof( remoteaddr ) );
    remoteaddr.sin_family = AF_INET;
    remoteaddr.sin_port = htons( UDP_TEST_PORT );
    remoteaddr.sin_addr.s_addr = inet_addr( UDP_SERVER_IP );

    int rc = connect( sockfd, (struct sockaddr *)&remoteaddr, addr_len );
    if ( rc == -1 && errno != EINTR && errno != EINPROGRESS ) {
        close( sockfd );
        perror( "connect failed" );
        exit( 3 );
    }

    printf( "[%s:%d] connect to [%s:%d]\n", inet_ntoa( localaddr.sin_addr ), ntohs( localaddr.sin_port ), inet_ntoa( remoteaddr.sin_addr ), ntohs( remoteaddr.sin_port ) );

    while ( 1 ) {
        bzero( buffer, sizeof( buffer ) );

        printf( "Please enter a string to send to server: \n" );

        /* 从标准输入设备取得字符串*/
        len = read( STDIN_FILENO, buffer, sizeof( buffer ) );

        /* 将字符串传送给server端*/
        // sendto( sockfd, buffer, len, 0, (struct sockaddr *)&remoteaddr, addr_len );
        write( sockfd, buffer, len );

        /* 接收server端返回的字符串*/
        // len = recvfrom( sockfd, buffer, sizeof( buffer ), 0, (struct sockaddr *)&remoteaddr, &addr_len );
        len = read( sockfd, buffer, sizeof( buffer ) );
        printf( "Receive from server: %s\n", buffer );
    }

    return 0;
}

// ----------------------------------------------------------------------------
// End of udp_client.c
