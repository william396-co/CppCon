#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Item
{
    int32_t id;
    int64_t cnt;

    Item( int32_t id, int64_t cnt )
        : id { id }, cnt { cnt } {}
    Item()
        : id {}, cnt {} {}

    Item( Item const & other ) noexcept
        : id { other.id }, cnt { other.cnt }
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
    Item & operator=( Item const & other ) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        id = other.id;
        cnt = other.cnt;
        return *this;
    }

    Item( Item && other ) noexcept
        : id { other.id }, cnt { other.cnt }
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    Item & operator=( Item && other ) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        id = other.id;
        cnt = other.cnt;
        return *this;
    }

    friend std::ostream & operator<<( std::ostream & os, Item const & item );
};
std::ostream & operator<<( std::ostream & os, Item const & item )
{
    return os << "{id:" << item.id << ",cnt:" << item.cnt << "}";
}

using ItemList = std::vector<Item>;
using ItemMap = std::map<std::string, ItemList>;

ItemMap move_test()
{
    ItemMap ret;
    for ( auto const & s : { "abc", "def" } ) {

        ItemList list;
        list.emplace_back( 1, 11 );
        list.emplace_back( 2, 22 );
        ret.emplace( s, std::move( list ) );
    }

    return ret;
}

int main()
{

    auto res = move_test();

    for ( auto const & it : res ) {
        std::cout << it.first << "[";

        for ( auto const & it2 : it.second ) {
            std::cout << it2;
        }
        std::cout << "]\n";
    }

    return 0;
}

