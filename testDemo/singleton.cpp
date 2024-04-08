#include <iostream>

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if ( !instance_ ) {
            instance_ = new Singleton();
        }
        return instance_;
    }

private:
    Singleton()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
    ~Singleton()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    static Singleton * instance_;
};

Singleton * Singleton::instance_ = nullptr;

int main()
{
    auto ins = Singleton::getInstance();

    return 0;
}
