#include <bits/stdc++.h>
using namespace std;
/*
Write a function that takes input an sorted array of distinct integers , which is rotated about a pivot point and finds the index of any given element
*/
/**
 * If the left half is sorted, and the key is in the left half, search the left half, else search the
 * right half
 * 
 * Args:
 *   a (vector<int>): The array to search in
 *   key (int): The element to be searched
 * 
 * Returns:
 *   The index of the element in the array.
 */
int rotatedsearch(vector<int> a, int key)
{
    int n = a.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        // 2 Cases
        if (a[s] <= a[mid])
        {
            // left
            if (key >= a[s] and key <= a[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            // right
            if (key >= a[mid] and key <= a[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}
/**
 * The function finds the pivot element and then calls the binary search function on the left and right
 * subarrays
 *
 * Returns:
 *   The index of the element in the array.
 */
int main()
{
    vector<int> a{4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;
    cout << rotatedsearch(a, key) << endl;
    return 0;
}