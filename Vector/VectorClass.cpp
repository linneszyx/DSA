#include <iostream>
#include "vector.h"
using namespace std;
int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
   // v.pop_back();
    cout<<v.size()<<endl; //5
    cout<<v.capacity()<<endl; //8
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.at(2)<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}