#include<bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};
int main()
{
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(int);
    priority_queue<int> max_heap; //default max_heap
    priority_queue<int,vector<int>,Compare> min_heap;
    for(int x : arr){
        max_heap.push(x);
    }
    for(int x : arr){
        min_heap.push(x);
    }
    cout<<"Max Heap Gives Result In Descending Order\n";
    while (!max_heap.empty())
    {
        cout<<max_heap.top()<<endl;
        max_heap.pop();
    }
    cout<<"Min Heap Gives Result In Ascending Order\n";
    while (!min_heap.empty())
    {
        cout<<min_heap.top()<<endl;
        min_heap.pop();
    }
return 0;
}