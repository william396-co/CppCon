#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

struct Skill
{
    int id;
    int level;
};

using SkillList = std::vector<Skill>;

std::map<int, int> sl = { { 1000, 1 }, { 1100, 2 }, { 1200, 3 }, { 1300, 4 }, { 1400, 5 }, { 1500, 6 } };

int getRankId( int score )
{
    assert( !sl.empty() );

    auto it = sl.lower_bound( score );
    if ( it != sl.end() ) {
        if ( score < it->first  && it != sl.begin()) {
            --it;
        }
        return it->second;
    }

    return ( --it )->second;
}

int main()
{

    for ( int i = 0; i != 2000; i += 100 ) {
        std::cout << "getRankId(" << i << ")=" << getRankId( i ) << "\n";
        std::cout << "getRankId(" << i + 99 << ")=" << getRankId( i + 99 ) << "\n";
    }

    SkillList slist = { { 101, 1 }, { 102, 3 } };
    std::for_each( slist.begin(), slist.end(), []( auto skill ) {
        std::cout << skill.id << "," << skill.level << "\n";
    } );

    auto it = std::find_if( slist.begin(), slist.end(), []( auto skill ) { return skill.id == 101; } );
    if ( it != slist.end() ) {
        it->level = 100;
    }

    std::for_each( slist.begin(), slist.end(), []( auto skill ) {
        std::cout << skill.id << "," << skill.level << "\n";
    } );

    return 0;
}
