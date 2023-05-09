#include "../../util/print.h"

#include <vector>
#include <variant>
#include <functional>

class Circle
{
public:
    explicit Circle( double rad )
        : radius { rad }
    {}
    double getRadius() const noexcept { return radius; }

private:
    double radius;
};

class Square
{
public:
    explicit Square( double s )
        : side { s } {}

    double getSide() const noexcept { return side; }

private:
    double side;
};

class Ellipse
{
public:
    explicit Ellipse( double r1, double r2 )
        : m_r1 { r1 }, m_r2 { r2 } {}

private:
    double m_r1;
    double m_r2;
};

// No base class required!
// Operations can be non-intrusively be added
class Draw
{
public:
    explicit Draw( int id )
        : id { id } {}
    void operator()( Circle const & circle ) const
    {
        println( "Draw Circle(", id, ")" );
    }
    void operator()( Square const & square ) const
    {
        println( "Draw Sqaure(", id, ")" );
    }

private:
    int id;
};

// Add operations rotate
class Rotate
{
public:
    void operator()( Circle const & circle ) const
    {
        println( "Rotate Circle" );
    }
    void operator()( Square const & square ) const
    {
        println( "Rotate Sqaure" );
    }
};

using Shape = std::variant<Circle, Square>;
using RoundShape = std::variant<Circle, Ellipse>;

void drawAllShapes( std::vector<Shape> const & shapes )
{
    int id = 0;
    for ( auto const & s : shapes ) {
        std::visit( Draw { ++id }, s );
        //        std::visit(Rotate{}, s, id);
    }
}

/*
 * This style of programming has many advantages:
 * . There is no inheritance hierarchy(non-intrusive)
 * . No cycle dependency(implementation flexibility)
 * . The code is so much simpler(KISS)
 * . There are no virtual functions
 * . There are no pointers or indirections
 * . There is no manual dynamic memory allocation
 * . There is no need to manage lifetime
 * . There is no lifetime-related issue(no need for smart pointers)
 * . The performance is better
 *
 * These are the advantages of value semantics
 *
 * Potential  Disadvantages of std::variantta
 * . Use alternatives of approximately the same size
 *  - Revert to pointers(with a performance disadvantage)
 *  - Use the Proxy design pattern
 *  - Use the Bridge design pattern
 *
 * . Be aware that std::variant reveals a lot of information(dependencies!)
 *  - Revert to pointers(with a performance disadvantage)
 *
 */

/*
 * Comparsion of Visitor Implementations
 * ----------------------------------------------------------------------
 *  Classic Visitor                  |   Modern Vistor with
 *                                   |      std::variant
 * ----------------------------------------------------------------------
 *  Intrusive                        |   Non-intrusive
 *  ( base class)                    |  (can be added on-the-fly)
 * ----------------------------------------------------------------------
 *  Reference-semantics              |   Value-semantics
 *  (based on references/pointers)   |   (based on values)
 * ----------------------------------------------------------------------
 *     OOP style                     |   Procedural style
 * ----------------------------------------------------------------------
 *     Slow                          |        Fast
 *  (many virtual functions,         |  (no virtual functions, contiguous
 *    scattered memory access)       |    memory access)
 * ----------------------------------------------------------------------
 */

int main()
{

    using Shapes = std::vector<Shape>;

    Shapes shapes;
    shapes.emplace_back( Circle { 2.0 } );
    shapes.emplace_back( Square { 1.5 } );
    shapes.emplace_back( Circle { 4.2 } );

    drawAllShapes( shapes );
    return 0;
}
