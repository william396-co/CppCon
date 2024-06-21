#include <map>
#include <iostream>

std::map<int, int> mp = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 } };

int findIdx( int idx )
{
    if ( mp.empty() ) {
        return 0;
    }

    auto it = mp.find( idx );
    if ( it != mp.end() ) {
        return it->second;
    }

    return ( --it )->second;
}

int main()
{

    std::cout << findIdx( 5 ) << "\n";
    std::cout << findIdx( 3 ) << "\n";
    std::cout << findIdx( 10 ) << "\n";

    return 0;
}
