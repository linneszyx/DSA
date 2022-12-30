#include <bits/stdc++.h>
using namespace std;
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void fillarray(int *arr, int i, int n, int value)
{
    // base case
    if (i == n)
    {
        printArray(arr, n);
    }
    arr[i] = value;
    //recursive case
    fillarray(arr, i + 1, n, value + 1);
    //backtracking case
    arr[i] = -1*arr[i];
    printArray(arr,n);
}
int main()
{
    int arr[5] = {0};
    int n;
    cin >> n;
    fillarray(arr, 0, n, 1);
    cout << endl;
    printArray(arr, n);
    return 0;
}