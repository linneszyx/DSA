#include<bits/stdc++.h>
using namespace std;
int linear_search(int arr[],int n,int key){
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==key)
       { return i;}
    }
    return -1;

}
int main(){
int arr[] = {12,23,4,2,3,534};
int n = sizeof(arr)/sizeof(int);
int key;
cin>>key;
int index = linear_search(arr,n,key);
if(index!=1){
    cout<<key<<" is present at the index "<<index<<endl;
}
else {
    cout<<key<<" is not present in the array"<<endl;
}
return 0;
}