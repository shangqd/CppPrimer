#include <iostream>

int main()
{
    //
    /*int i =0;
    std::cout<<i<<std::endl;
    int i1={0};
    std::cout<<i1<<std::endl;
    int i2{0};
    std::cout<<i2<<std::endl;
    int i3(0);
    std::cout<<i3<<std::endl;
    long double pi=3.1415926;
    //int c{pi};
    int c(pi);
    std::cout<<c<<std::endl;      
    int n =3.14;
    std::cout<<n<<std::endl; 
    int _;  
    _=9;
    std::cout<<_<<std::endl; 
    int p=100,sum=0;
    for(int p=0;p!=10;p++)
    sum+=p;
    std::cout<<p<<"   "<<sum<<std::endl; 
    int i =1024;
    int &r = i;
    std::cout<<&r<<"   "<<&i<<std::endl; 
    std::cout<<r<<std::endl; 
    int& r1 = i;
    std::cout<<&r1<<"   "<<r1<<std::endl;


    int p = 10;
    int *pi = &p;
    int *ppi =pi;
    std::cout<<&p<<"   "<<pi<<"   "<<ppi<<std::endl; 
    std::cout<<p<<"   "<<*pi<<"   "<<*ppi<<std::endl; 
    int i = 3.14;
    int &r = i;
    std::cout<<i<<"   "<<r<<std::endl; 

    int i=0,&r1=i;
    double d=0,&r2=d;
    r2=3.14;
    r2=r1;
    i=r2;
    r1=d;
    std::cout<<i<<"   "<<r1<<"  "<<d<< "  "<<r2<<std::endl;  
    
    int *p=0;
    std::cout<<p<<std::endl;

    int i=1;
    int *pi=&i;
    *pi=2;
    std::cout<<i<<"  "<<pi<<"   "<<*pi<<std::endl;  

    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;
    std::cout<<p1<<"  "<<p2<<"   "<<p3<<std::endl;  

    int *p4;
    *p4=2;
    std::cout<<p<<"   "<<*p4<<std::endl;   

    int i=10;
    int *p=&i;
    *p=*p**p;
    std::cout<<p<<"  "<<*p<<std::endl; 

    int i = 1024;
    int *pi = &i;
    int **ppi=&pi;
    **ppi=10;
    std::cout<<i<<"  "<<**ppi<<"   "<<ppi<<"  "<<*ppi<<"  "<<pi<<std::endl;*/

    int i = 2;
    //const int i = 2;
    const int &r = i;
    //int &r1 = r;
    i = 6;
    std::cout << r << std::endl;
 
    double d = 3.14;
    const int &r2 = d;
    d = 4.5;
    std::cout << r2 << std::endl;
    const double *p = &d;
    std::cout << *p << std::endl;
    d = 1.5;
    const double *p2 = p;
    std::cout << *p2 << std::endl;

    double *const p3 = &d;
    *p3 = 10;
    std::cout << *p3 << std::endl;
    
}