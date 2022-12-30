/**
 * The outer loop runs n-1 times and the inner loop runs n-1-i times
 * 
 * Args:
 *   arr (int): The array to be sorted
 *   n (int): size of the array
 */
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int n)
{
    for (int times = 1; times <= n - 1; times++)
    {
        // repeated swapping
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}