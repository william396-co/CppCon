#include "../util/print.h"

#include <iostream>
#include <algorithm>
#include <ostream>
#include <string>
#include <map>
#include <vector>

class A
{
public:
    explicit A( std::string const & n, int id )
        : a{id}, name { n }
    {
        println( __FUNCTION__, "(", name, ",", a, ")" );
    }

    ~A()
    {
        println( __FUNCTION__, "(", name, ",", a, ")" );
    }

    friend std::ostream & operator<<( std::ostream & os, A const & rhs );

private:
    int a;
    std::string name;
};

std::ostream & operator<<( std::ostream & os, A const & rhs )
{
    return os << rhs.name << "," << rhs.a;
}

using ListA = std::vector<std::pair<int, A *>>;
using MapListA = std::map<int, ListA>;

MapListA maplist;

void clearAll()
{
    println( __FUNCTION__ );
    for ( auto & i : maplist ) {
        for ( auto & j : i.second ) {
            delete j.second;
        }
        i.second.clear();
    }
    maplist.clear();
}

void addAll()
{
    println( __FUNCTION__ );
    ListA lista = {
        { 1, new A { "hello one", 11 } },
        { 2, new A { "hello two", 12 } },
        { 3, new A { "hello three", 13 } }
    };

    ListA listb = {
        { 11, new A { "hello B one", 111 } },
        { 12, new A { "hello B two", 112 } },
        { 13, new A { "hello B three", 113 } }
    };
    maplist.emplace( 1, std::move( lista ) );
    maplist.emplace( 2, std::move( listb ) );
}

A * getA( int i, int j )
{
    auto it = maplist.find( i );
    if ( it != maplist.end() ) {
        auto pos = std::find_if( it->second.begin(), it->second.end(), [j]( auto & who ) { return who.first == j; } );
        if ( pos != it->second.end() ) {
            return pos->second;
        }
    }
    return nullptr;
}

int main()
{

    for ( int i = 0; i < 10; ++i ) {
        println( "=============================", i, "==============" );
        clearAll();
        addAll();
        auto a = getA( 1, 1 );
        if ( a ) println( a );

        auto b = getA( 2, 11 );
        if ( b ) println( b );
    }

    return 0;
}
