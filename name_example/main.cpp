#include "../util/print.h"
#include "../util/str_util.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

int main()
{

    std::string filename( "name.txt" );

    std::string line;
    std::unordered_map<std::string, double> Dict;

    std::ifstream input( filename );
    if ( !input.is_open() ) {
        println( "Could not open the file -", filename );
        return 1;
    }

    while ( getline( input, line ) ) {
        auto res = utils::split( line, "" );
        if ( res.size() > 1 ) {
            Dict.emplace( res[0], atof( res[1].c_str() ) );
        }
    }

    for ( const auto & it : Dict ) {
        println( it.first, ",", it.second );
    }
    return 0;
}
