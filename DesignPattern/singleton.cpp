#include <stdio.h>

class Singleton
{
private:
    Singleton();
    Singleton(const Singleton &s);
    Singleton& operator= (const Singleton &s);

public:
    static Singleton* getInstance();

private:
    static Singleton *instance;

};

Singleton* Singleton::instance = new Singleton();

Singleton::Singleton()
{

}

Singleton* Singleton::getInstance()
{
    return instance;
}

int main()
{
    printf("hello\n");
    return 0;
}