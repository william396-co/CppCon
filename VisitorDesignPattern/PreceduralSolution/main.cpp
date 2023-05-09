#include "../../util/print.h"

#include <vector>
#include <memory>

enum ShapeType
{
    circle,
    square,
};

class Vector2D
{
};

class Shape
{
public:
    explicit Shape( ShapeType t )
        : type { t } {}

    ShapeType getType() const noexcept { return type; }
    virtual ~Shape() {}

private:
    ShapeType type;
};

class Circle : public Shape
{
public:
    explicit Circle( double rad )
        : Shape { circle }, radius { rad }
    {}

private:
    double radius;
};

void draw( Circle const & circle )
{
    println( __PRETTY_FUNCTION__ );
}
void rotate( Circle const & circle, double const & rd )
{
}
void translate( Circle const & circle, Vector2D const & v2 )
{
}

class Square : public Shape
{
public:
    explicit Square( double s )
        : Shape { square },
          side { s } {}

private:
    double side;
};

void draw( Square const & square )
{
    println( __PRETTY_FUNCTION__ );
}
void rotate( Square const & square, double const & rd )
{
}
void translate( Square const & square, Vector2D const & v2 )
{
}

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const & shapes )
{
    for ( auto const & s : shapes ) {
        switch ( s->getType() ) {
            case circle:
                draw( *static_cast<Circle const *>( s.get() ) );
                break;
            case square:
                draw( *static_cast<Square const *>( s.get() ) );
                break;
        }
    }
}

int main()
{

    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes;
    shapes.emplace_back( std::make_unique<Circle>( 2.0 ) );
    shapes.emplace_back( std::make_unique<Square>( 1.5 ) );
    shapes.emplace_back( std::make_unique<Circle>( 4.2 ) );

    drawAllShapes( shapes );
    return 0;
}
