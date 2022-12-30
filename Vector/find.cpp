#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {10, 12, 14, 2, 4, 6, 7, 8};
    int key;
    cin >> key;
    vector<int>::iterator it = find(arr.begin(), arr.end(), key);
    if (it != arr.end())
    {
        cout << "Present at Index " << it - arr.begin() << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }
    return 0;
}