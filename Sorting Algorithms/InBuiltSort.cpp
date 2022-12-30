#include <bits/stdc++.h>
using namespace std;
// bool compare(int a,int b){
//     return a>b;
// }
int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n, greater<int>()); // O(logN) // comparator //greator
    // reverse(arr,arr+n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}