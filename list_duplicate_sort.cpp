#include<iostream>
#include<forward_list>
using namespace std;


int main()
{
    forward_list<int> list1 = {1,2,3,4,5,6};
    forward_list<int> list2 = {1,2,3};

    list1.sort();
    list2.sort();

    forward_list<int>::iterator i1;
    forward_list<int>::iterator i2;
    i1 = list1.begin();
    i2 = list2.begin();

    while(i1 != list1.end())
    {
        while(i2 != list2.end())
        {
           if(*i1 > *i2) i1++;
        }
    }

}