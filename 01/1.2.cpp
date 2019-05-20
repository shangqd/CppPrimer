#include <iostream>
#include "1.2.h"
using namespace std;
int main()
{ 
    /*std::cout<<"enter tow numbers:"<<std::endl;
    int v1=0,v2=0;
    std::cin>>v1>>v2;
    std::cout<<v1<<" + "<<v2<<" is "<<v1+v2;
    std::cout<<std::endl;
    std::cout<<"the num of "<< v1;
    std::cout <<" and "<<v2;
    std::cout <<" is "<<v1+v2<<std::endl;*/
    //std::cout<<"/*";
    //std::cout<<"*/";
    //std::cout<<"/*"/*"*/;
    //std::cout<</*"*/"/*"/*"*/;
    /*int sum =0,value=0;
    while(std::cin>>value)
    {
        sum+=value;
    }
    std::cout<<" sum of these num is "<<sum<<std::endl;*/
    /*Sales_item book;
	cin >> book;
	cout << book << endl;
    Sales_item item1, item2;
	int cnt = 1;
	cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
		++cnt;
	else
		cnt = 1;
	cout << cnt << endl;*/
    Sales_item total;
	if (cin >> total)
	{
		Sales_item trans;
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}