#include <bits/stdc++.h>
using namespace std;
/**
 * It takes the last element as pivot, places the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to
 * right of pivot
 * 
 * Args:
 *   a (vector<int>): the array to be sorted
 *   s (int): start index
 *   e (int): end of the array
 * 
 * Returns:
 *   The index of the pivot element.
 */
int partition(vector<int> &a, int s, int e)
{
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j <= e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
/**
 * We are taking the last element as the pivot and then we are partitioning the array around the pivot.
 * 
 * 
 * We are then recursively calling the quicksort function on the left and right subarrays.
 * 
 * Args:
 *   a (vector<int>): the array to be sorted
 *   s (int): start index
 *   e (int): end index
 * 
 * Returns:
 *   The pivot element
 */
void quicksort(vector<int> &a, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // rec case
    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}
int main()
{
    vector<int> arr{10, 1, 4, 7, 8, 25, 3};
    cout << arr.size() << endl;
    int n = arr.size();
    quicksort(arr, 0, n - 1);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}