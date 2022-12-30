#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int currrent = arr[i];
        int previous = i - 1;
        while (previous >= 0 and arr[previous] > currrent)
        {
            arr[previous + 1] = arr[previous];
            previous = previous - 1;
        }
        arr[previous + 1] = currrent;
    }
}
int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}