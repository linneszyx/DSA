#include<bits/stdc++.h>
using namespace std;
int main(){
int marks[100];
int n;
cout<<"Enter The Number Of Students : ";
cin>>n;
for(int i = 0;i<n;i++){
    cin>>marks[i];
    marks[i] *=2;
}
for(int i = 0;i<n;i++){
    cout<<marks[i]<<",";
}
cout<<endl;
return 0;
}