#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <string_view>
#include <functional>
#include "../util/print.h"

void * operator new( std::size_t sz )
{
    std::cout << "Allocating: " << sz << '\n';
    return std::malloc( sz );
}

struct string_hash
{
    using hash_type = std::hash<std::string_view>;
    using is_transparent = void;

    std::size_t operator()(const char* str)const{return hash_type{}(str);}
    std::size_t operator()(std::string_view str)const{return hash_type{}(str);}
    std::size_t operator()(std::string const& str)const{return hash_type{}(str);}
};

int main()
{
    std::map<std::string, int, std::less<>> intMap {
        { "Hello Super Long String", 1 },
        { "Another Longish String", 2 },
        { "This cannot fall into SSO buffer", 3 }
    };
    std::cout << "Lookup in intMap with by const char*:\n";
    std::cout << intMap.count( "Hello Super Long String" ) << '\n';

    println("========================");
//  std::unordered_map<std::string, int> strMap{
    std::unordered_map<std::string, int,string_hash, std::equal_to<>> strMap {
        { "Hello Super Long String", 1 },
        { "Another Longish String", 2 },
        { "This cannot fall into SSO buffer", 3 }
    };
    std::cout << "Lookup in strMap with by const char*:\n";
    std::cout << strMap.count( "Hello Super Long String" ) << '\n';

    return 0;
}
