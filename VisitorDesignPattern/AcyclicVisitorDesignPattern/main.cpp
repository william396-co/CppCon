#include "../../util/print.h"

#include <vector>
#include <memory>

enum ShapeType
{
    circle,
    square,
};

class AbstractVistor
{
public:
    virtual ~AbstractVistor()
    {
        println( __PRETTY_FUNCTION__ );
    }
};

template<typename T>
class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit( T const & ) const = 0;
};

class Shape
{
public:
    explicit Shape( ShapeType t )
        : type { t } {}

    virtual void accept( AbstractVistor * ) = 0;
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

    virtual void accept( AbstractVistor * v ) override
    {
        auto cv = dynamic_cast<Visitor<Circle> *>( v );
        if ( cv ) {
            cv->visit( *this );
        }
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
    virtual void accept( AbstractVistor * v ) override
    {
        auto cv = dynamic_cast<Visitor<Square> *>( v );
        if ( cv ) {
            cv->visit( *this );
        }
    }

private:
    double side;
};

class Draw : public AbstractVistor,
             public Visitor<Circle>,
             public Visitor<Square>
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
    virtual ~Draw()
    {
        println( __PRETTY_FUNCTION__ );
    }
};

//#define USE_RAII

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const & shapes )
{
#ifdef USE_RAII
    std::unique_ptr<AbstractVistor> op = std::make_unique<Draw>();
#else
    auto op = new Draw {};
#endif
    for ( auto const & s : shapes ) {
#ifdef USE_RAII
        s->accept( op.get() ); // use unique_ptr to manager resource(RAII)
#else
        s->accept( op ); // need delete op by yourself
#endif
    }

#ifndef USE_RAII
    delete op;
#endif
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
