#include <iostream>
#include <vector>
#include <algorithm>

struct Skill
{
    int id;
    int level;
};

using SkillList = std::vector<Skill>;

int main()
{

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
