#include <iostream>
#include <assert.h>
#include <string>

const char* fun()
{
    std::string str("abc");
    return str.c_str();
}

int main()
{
    const char *str = fun();
    std::cout << str << std::endl;
    return 0;
    int a = 101;
    int &b = a;
    assert(&a == &b);
    int *c = &a;
    assert(c == &a);
    assert(*c==a);
    assert(&c != (void*)&a);
    std::cout << "OK" << std::endl;
}