
#include <iostream>
#include <assert.h>
#include <vector>

void f3_1()
{
    using std::cout;
    using std::endl;
    cout << "3.1" << endl;
}

void f3_2()
{
    using namespace std;
    string str1;
    string str2(str1);
    string str3 = str2;
    string str4("直接初始化");
    string str5 = "复制初始化";
    assert(isalnum('a') && isalnum('A') && isalnum('1') && isalnum('#') == 0);
    assert(isalpha('a') && isalpha('A') && isalpha('1') == 0 && isalpha('#') == 0);
    assert(islower('a') && islower('A') == 0);
    assert(isupper('a') == 0 && isupper('A'));
    string str6(10,'a');
    for (auto &c : str6)
    {
        c = toupper(c);
    }
    cout << str1 << str2 << str3 << str4 << str5 << str6 << endl;
}

void f3_3()
{
    using std::vector;
    vector<int> vi1(10,1);
    vector<int> vi2(vi1);
    vector<int> vi3 = vi2;
    vector<int> vi4{1,2,3};
    vector<int> vi5 = {1,2,3};
    vi5.push_back(4);
    for (auto a : vi5)
    {
        std::cout << a << std::endl;
    }
    
    vi5.pop_back();
    for (auto a : vi5)
    {
        std::cout << a << std::endl;
    }
    
}

void f3_4()
{
    using std::vector;
    vector<int> vi5 = {1,2,3};
    auto ite = vi5.begin();
    ite += 2;
    std::cout << typeid(vi5.begin()).name() << std::endl;
    std::cout << typeid(vector<int>::pointer).name() << std::endl;
    std::cout << typeid(int*).name() << std::endl;
}

const char* f3_5_()
{
    std::string str("abc");
    //char *str1 = "abc";
    //char str2[] = "abc";
    //return str2;
    //return str1;
    return str.c_str();
}

void f3_5()
{
    int a[] = {1,2,3};
    for (auto &i : a)
    {
        i++;
    }
    for (auto i : a)
    {
        std::cout << i << std::endl;
    }
    for (auto ite = std::begin(a); ite != std::end(a); ++ite)
    {
        std::cout << *ite << std::endl;
    }

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        std::cout << a[i] << std::endl;
    }
    //const char *p = f3_5_();
    std::cout << f3_5_() << std::endl;
}

void f3_6()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    //int a[] = {1,2,3}; 不能编译
    for (auto &row : a)
    {
        for (auto &a : row)
        {
            std::cout << a << ",";
        }
        std::cout << std::endl;
    }
    //不能编译通过
    //for (auto row : a)
    //{
    //    for (auto &a : row)
    //    {
    //        std::cout << a << ",";
    //    }
    //    std::cout << std::endl;
    //}
}

int main()
{
    f3_5();
    return 0;
}