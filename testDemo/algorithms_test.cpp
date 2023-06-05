#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <functional>
#include <map>

bool is_match( char c1, char c2 )
{
    return ( c1 == '{' && c2 == '}' )
        || ( c1 == '[' && c2 == ']' )
        || ( c1 == '(' && c2 == ')' );
}

int main( int argc, char * argv[] )
{

    std::string input = { "[()[{}()]]" };

    input = "[()[{}()]](())()";

    int level = 0;
    std::stack<std::pair<char, int>> stk;
    std::map<int, std::vector<std::string>> output;
    for ( char const & c : input ) {
        if ( stk.empty() ) {
            stk.push( { c, level++ } );
            continue;
        }
        auto top = stk.top();
        if ( is_match( top.first, c ) ) {
            // std::cout << top.first << c << "[" << level << "\n";
            std::string tmp = { top.first };
            tmp.push_back( c );
            auto it = output.find( level );
            if ( it != output.end() )
                it->second.emplace_back( tmp );
            else
                output.emplace( level, std::vector<std::string> { tmp } );
            stk.pop();
            --level;
            continue;
        }
        stk.push( { c, level++ } );
    }

    for ( auto && it : output ) {
        for ( auto & iter : it.second ) {
            std::cout << iter << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
