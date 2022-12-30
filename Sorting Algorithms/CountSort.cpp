#include <bits/stdc++.h>
using namespace std;
void count_sort(int arr[], int n)
{
    //largest element
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest,arr[i]);
    }
    //create a count array/vector
    vector<int> freq(largest+1,0);
    //update the freq array
    for(int i =0;i<n;i++){
        freq[arr[i]]++;
    }
    //put back the element from freq into original array
    int j  = 0;
    for (int i = 0; i <=largest; i++)
    {
        while(freq[i]>0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
    
}
int main()
{
    int arr[] = {88,10,12,15,1,5,12,10,88};
    int n = sizeof(arr) / sizeof(int);
    count_sort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
