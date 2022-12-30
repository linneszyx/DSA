#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000] = "apple";
    char b[1000];
    // strlen
    cout << strlen(a) << endl;
    // strcpy
    strcpy(b, a);
    cout << b << endl;
    
    // strcmp
    cout << strcmp(a,strcat(b,a)) << endl;
    
    return 0;
}