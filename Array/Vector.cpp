#include <bits/stdc++.h>
using namespace std;
int main()
{
    //vector<int> arr ;//= {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr(10,7); // fill constructor
    //arr.pop_back(); // pop_back
    arr.push_back(9);//push_back 0(1)
    for(int i = 0;i<arr.size();i++){
        cout<<i<<" ";
    }
    cout << arr.size() <<endl; // size of the vector (no. of elements)
    cout << arr.capacity()<<endl;// Capacity of the vector


    return 0;
}