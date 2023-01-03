#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<string> mov;
    mov.push("Hell");
    mov.push("JS");
    mov.push("Ruby");
    while (!mov.empty())
    {
        cout << mov.top() << endl;
        mov.pop();
    }
    return 0;
}