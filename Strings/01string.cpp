#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // char a[] = "abcdeghi";
    // cout << a << endl;
    char sentence[100];
    char temp = cin.get();
    int len = 0;
    while (temp != '\n')
    {
        sentence[len++] = temp;
        // Update the value of temp
        temp = cin.get();
    }
    sentence[len] = '\0';
    cout << "Length = " << len << endl;
    cout << sentence << endl;
    // cout << strlen(a) << endl;//number of visible characters
    // cout << sizeof(a) << endl;//+1 because of null character
}