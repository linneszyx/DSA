#include <bits/stdc++.h>
using namespace std;
/**
 * It takes in an array, the starting index and the ending index of the array and merges the two sorted
 * subarrays into one sorted array
 * 
 * Args:
 *   arr (vector<int>): The array to be sorted
 *   s (int): start index of the array
 *   e (int): end index of the array
 * 
 * Returns:
 *   Nothing
 */
void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vector<int> temp;
    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    // copy remaining elements from first arr
    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }
    // or copy remaining elements from second arr
    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }
    // copy back the elements from temp to original arr
    int index = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[index++];
    }
    return;
}
// Sorting method
/**
 * We divide the array into two halves, sort the two halves and then merge the two sorted halves
 * 
 * Args:
 *   arr (vector<int>): The array to be sorted
 *   s (int): start index of the array
 *   e (int): end index of the array
 * 
 * Returns:
 *   The merge function is being returned.
 */
void mergeSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    return merge(arr, s, e);
}
int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 8};
    int s = 0;
    int e = arr.size() - 1;
    mergeSort(arr, s, e);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout<<endl;
    return 0;
}