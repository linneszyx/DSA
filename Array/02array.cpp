#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int n){
cout<<"In Function "<<sizeof(arr)<<endl;

for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<endl;
}
}
int main(){
int ar[] = {1,2,3,4,5,6};
int n = sizeof(ar)/sizeof(int);
cout<<"In Main "<<sizeof(ar)<<endl;
for (int i = 0; i < n; i++)
{
    cout<<ar[i]<<endl;
}

printArray(ar,n);
return 0;
}