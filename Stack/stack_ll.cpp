#include <bits/stdc++.h>
#include "stackLL.h"
using namespace std;
int main()
{
    Stack<char> s;
    s.push('l');
    s.push('i');
    s.push('n');
    s.push('n');
    s.push('e');
    s.push('s');
    s.push('z');
    s.push('y');
    s.push('x');
    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}