#include<bits/stdc++.h>
using namespace std;
/*
Run Length Encoding for String Compression
If compressed string is bigger than original return
original string
Input : aaabbccddee
Output : a3b2c2d2e2
Input : abcd
Output : abcd
*/
string compressString(string sarr)
{
    int n = sarr.length();
    string output;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while(i<n-1 and sarr[i+1]==sarr[i]){
            count++;
            i++;
        }
        output += sarr[i];
        output += to_string(count);
    }
    if(output.length()>sarr.length()){
        return sarr;
    }
    else{
        return output;
    }
}
int main(){
 string s1 = "aaabbccddee";
 cout<<compressString(s1)<<endl;
 string s2 = "abcd";
 cout<<compressString(s2)<<endl;
return 0;
}