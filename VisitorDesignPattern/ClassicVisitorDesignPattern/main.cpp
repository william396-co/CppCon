#include "../../util/print.h"

#include <vector>
#include <memory>

enum ShapeType
{
    circle,
    square,
};

class Circle;
class Square;
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() {}

    virtual void visit( Circle const & circle ) const = 0;
    virtual void visit( Square const & square ) const = 0;
};

class Shape
{
public:
    explicit Shape( ShapeType t )
        : type { t } {}

    virtual void accept( ShapeVisitor const & ) = 0;
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

    virtual void accept( ShapeVisitor const & v ) override
    {
        v.visit( *this );
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
    virtual void accept( ShapeVisitor const & v ) override
    {
        v.visit( *this );
    }

private:
    double side;
};

class Draw : public ShapeVisitor
{
public:
    virtual void visit( Circle const & circle ) const override
    {
        println( "Draw Circle" );
    }
    virtual void visit( Square const & square ) const override
    {
        println( "Draw Square" );
    }
};

// Add operations rotate
class Rotate : public ShapeVisitor
{
public:
    virtual void visit( Circle const & circle ) const override
    {
        println( "Rotate Circle" );
    }
    virtual void visit( Square const & square ) const override
    {
        println( "Rotate Square" );
    }
};

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const & shapes )
{
    for ( auto const & s : shapes ) {
        s->accept( Draw {} ); // accept is operations
        s->accept( Rotate {} );
    }
}

/*
 * Advantages:
 * . Allows the non-intrusive addition of operations(OCP)
 * . Isolates the implementation details of operations(SRP)
 *
 * Disadvantages:
 * .Impedes the addition of new types(shapes)
 * .Restrict operations to public interface of types
 * .Negatively affects performance(two virtual functions)
 *
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
