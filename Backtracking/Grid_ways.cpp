#include<bits/stdc++.h>
using namespace std;
int gridways(int i,int j,int x,int y)
{
    if(i==x-1 and j==y-1){
        return 1;
    }
    if(j>=y or i>=x){
        return 0;
    }
    int ans = gridways(i+1,j,x,y) + gridways(i,j+1,x,y);
    return ans;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<gridways(0,0,x,y);
    return 0;
}