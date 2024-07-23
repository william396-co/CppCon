#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char * argv[] )
{
    kat_arg0 = basename( argv[0] );
    bzero( &cp, sizeof( cp ) );
    cp.cp_keepalive = 1;
    cp.cp_keepidle = -1;
    cp.cp_keepcnt = -1;
    cp.cp_keepintvl = -1;

    while ( ( c = getopt( argc, argv, ":c:d:i:" ) ) != -1 ) {
        switch ( c ) {
            case 'c':
                cp.cp_keepcnt = parse_positive_int_option(
                    optopt, optarg );
                break;

            case 'd':
                cp.cp_keepidle = parse_positive_int_option(
                    optopt, optarg );
                break;

            case 'i':
                cp.cp_keepintvl = parse_positive_int_option(
                    optopt, optarg );
                break;

            case ':':
                warnx( "option requires an argument: -%c", optopt );
                usage();
                break;

            case '?':
                warnx( "unrecognized option: -%c", optopt );
                usage();
                break;
        }
    }

    if ( optind > argc - 1 ) {
        warnx( "missing required arguments" );
        usage();
    }

    ipport = argv[optind++];
    if ( parse_ip4port( ipport, &cp.cp_ip ) == -1 ) {
        warnx( "invalid IP/port: \"%s\"", ipport );
        usage();
    }

    (void)fprintf( stderr, "going connect to: %s port %d\n", inet_ntoa( cp.cp_ip.sin_addr ), ntohs( cp.cp_ip.sin_port ) );
    (void)fprintf( stderr, "set SO_KEEPALIVE  = %d\n", cp.cp_keepalive );
    (void)fprintf( stderr, "set TCP_KEEPIDLE  = %d\n", cp.cp_keepidle );
    (void)fprintf( stderr, "set TCP_KEEPCNT   = %d\n", cp.cp_keepcnt );
    (void)fprintf( stderr, "set TCP_KEEPINTVL = %d\n", cp.cp_keepintvl );
    rv = connectandwait( &cp );
    return ( rv == 0 ? EXIT_SUCCESS : EXIT_FAILURE );
}
