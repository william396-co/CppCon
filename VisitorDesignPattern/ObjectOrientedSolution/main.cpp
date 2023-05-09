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

    virtual void draw() const = 0;
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
    virtual void draw() const override
    {
        println( __PRETTY_FUNCTION__ );
    }
    double getRadius() const noexcept { return radius; }

private:
    double radius;
};

class Square : public Shape
{
public:
    explicit Square( double s )
        : Shape { square },
          side { s } {}

    double getSide() const noexcept { return side; }

    virtual void draw() const override
    {
        println( __PRETTY_FUNCTION__ );
    }

private:
    double side;
};

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const & shapes )
{
    for ( auto const & s : shapes ) {
        s->draw();
    }
}

/*
 * An OO solution may appear better, but has two serious flaws:
 * . Adding operations is intrusive and thus difficult
 * . Adding operations accumulates dependencies.
 */

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
