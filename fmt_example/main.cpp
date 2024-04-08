#include <iostream>
#include <sstream>
#include <format>
#include <vector>

#define ENUM_FORMAT (TYPE) \
template<> struct std::formatter<TYPE> {\
    template <typename ParseContext>\
    constexpr auto parse(ParseContext& pc) const -> decltype(pc.begin()) {\
        return pc.begin();\
    }\

template <typename FormatContext>\
auto format(TYPE const & value, FormatContext& fc) const -> decltype(fc.out()) {\
		return std::format_to(fc.out(), "{}", (int32_t)value); \
}\
};


// 节点类型
enum class HostType
{
    None = 0,   // 非法的主机节点
    Gate = 1,   // 网关服务器
    Scene = 2,  // 场景服务器
    World = 3,  // 世界服务器
    Copy = 4,   // 副本服务器
    Logger = 5, // 日志服务器
    Data = 6,   // 数据服务器
    Login = 7,  // 验证服务器
    Master = 8, // 管理服务器
    // TODO: ....
    Global = 11,  // 全局服务器
    Transit = 12, // 中转服务器
    Cross = 13,   // 跨服服务器
    Any = 255,    // 任何节点
};

typedef std::vector<HostType> HostTypes; // 节点类型列表

template<> struct std::formatter<HostTypes>
{
    template<typename ParseContext>
    constexpr auto parse( ParseContext & pc )
        -> decltype( pc.begin() )
    {
        return pc.begin();
    }
    template<typename FormatContext>
    auto format( const HostTypes & values, FormatContext & fc ) const -> decltype( fc.out() )
    {
        std::ostringstream out;
        for ( auto i = 0; i != values.size(); ++i ) {
            out << (int32_t)values[i];
            if ( i != values.size() - 1 ) {
                out << ",";
            }
        }
        return std::format_to( fc.out(), "[{}]", out.str() );
    }
};



template<> struct std::formatter<HostType>
{
    template<typename ParseContext>
    constexpr auto parse( ParseContext & pc ) -> decltype( pc.begin() )
    {
        return pc.begin();
    }

    template<typename FormatContext>
    auto format( const HostType & value, FormatContext & fc ) const -> decltype( fc.out() )
    {
        return std::format_to( fc.out(), "{}", (int32_t)value );
    }
};


// 战斗方
enum CombatSide
{
    eCombatSide_None = 0,  // 非法
    eCombatSide_Left = 1,  // 攻方
    eCombatSide_Right = 2, // 守方
    eCombatSide_Draw = 3,  // 平局
};

/*
template<> struct std::formatter<CombatSide>
{
    template<typename ParseContext>
    constexpr auto parse( ParseContext & pc )
    {
        return std::to_string( pc.begin() );
    }

    template<typename FormatContext>
    auto format( const CombatSide & value, FormatContext & fc ) const
    {
        return std::format_to( fc.out(), "{}", (int)value );
    }
};*/
ENUM_FORMAT(CombatSide)

int main()
{

    HostType ht = HostType::Master;
    std::cout << std::format( "ht:{}\n", ht );

    HostTypes hts = { HostType::Master, HostType::Cross };
    std::cout << std::format( "hts:{}\n", hts );

    CombatSide sd = eCombatSide_Left;
  //  std::cout<<std::format("combatside:{}\n",(int32_t)sd);

    return 0;
}
