#include <string>
#include <map>
#include "../util/print.h"

void * operator new( std::size_t sz )
{
    std::cout << "Allocating: " << sz << '\n';
    return std::malloc( sz );
}
int main()
{
    std::map<std::string, int, std::less<>> intMap {
        { "Hello Super Long String", 1 },
        { "Another Longish String", 2 },
        { "This cannot fall into SSO buffer", 3 }
    };
    std::cout << "Lookup in intMap with by const char*:\n";
    std::cout << intMap.count( "Hello Super Long String" ) << '\n';

    return 0;
}
