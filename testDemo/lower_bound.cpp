#include <iostream>

#include <map>
std::map<int, int> m = { { 3, 3 }, { 6, 6 }, { 9, 9 } };

int lookup( int key )
{
    auto it = m.lower_bound( key );
    if ( it != m.end() ) {
        if ( it->first == key ) {
            return it->second;
        }
        if ( it != m.begin() ) {
            return ( --it )->second;
        }
    } else {
        return m.rbegin()->second;
    }
    return 0;
}

int main()
{

    for ( int i = 0; i < 12; ++i ) {
        std::cout << "lookup(" << i << ")=" << lookup( i ) << "\n";
    }

    return 0;
}
