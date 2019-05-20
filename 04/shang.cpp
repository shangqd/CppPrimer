
#include <iostream>
#include <assert.h>
#include <map>
#include <memory>

void f4_1()
{
    std::cout << "右值可以用左值代替，反之则不行" << std::endl;
    int *a(nullptr);
    
    int b = 0;
    decltype(a) c = &b;
    *c = 1;
    assert(b == 1);

    decltype(*a) d = b;
    d = 2;
    assert(b == 2);
}

void f4_12()
{
    bool b = true;
    int a = b ? 1 : 2;
    std::cout << a << std::endl;
}

class A
{
public:
    A(int a_)
    {
        a = a_;
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A" << std::endl;
    }
    int a;
};

void test_1()
{
    std::shared_ptr<A> p = std::make_shared<A>(1);
    auto q(p);
    q = p;
    assert(p == q);
    q.reset();
    std::cout << p->a << p.unique() << std::endl;
    std::cout << p.use_count() << std::endl;
    std::cout << q.use_count() << std::endl;
}

void test_2()
{
    std::unique_ptr<A> p = std::make_unique<A>(2);
    decltype(p) q(p.release());
    // 编译错误
    // auto q = p;
    std::cout << q->a << std::endl;
}

class CC
{
private:
    CC()
    {

    }
public:
    CC(int a)
    {

    }

};

class AA
{
public:
    AA()
    {
        std::cout << "AA" << std::endl;
        i = 100;
    }

    explicit AA(const AA& str)
    {
        std::cout << "AA2" << std::endl;
        i = 100;
    }
    
    AA& operator =(const AA& str)
    {
        std::cout << "AA =" << std::endl;
        return *this;
    }
    int i;
    CC cc = 1;
};

void test_3()
{
    CC cc = 100;
    std::shared_ptr<int> sp(new int(10));
    std::weak_ptr<int> wp(sp);
    wp = sp;
    std::cout << sp.use_count() << std::endl;
    std::cout << sp.use_count() << std::endl;
    if (wp.expired() == false)
    {
        std::cout << *(wp.lock()) << std::endl;
    }
    //int abc = 123;
    int &&a = 123;// std::move(abc);
    std::cout << &a << std::endl;

}

void fun(AA &aa)
{
    std::cout << "&" << aa.i << std::endl;
}

void fun(AA &&aa)
{
    std::cout << "&&" << aa.i << std::endl;
}

int main()
{
    AA aa;
    fun(aa);
    //test_3();
    return 0;
}