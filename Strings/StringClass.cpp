#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string s;//dynamic array
    // getline(cin, s,'.');
    // for(char x : s){
    //     cout<<x<<endl;
    // }
    // cout << s << endl;
    int n = 3;
    string s;
    vector<string> sarr;
    string temp;
    while(n--)
    { getline(cin,temp,'.');
        sarr.push_back(temp);
    }
    for(string x : sarr){
        cout<<x<<","<<endl;
    }
    return 0;
}