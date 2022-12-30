#include <bits/stdc++.h>
using namespace std;
//Brute Force Approach O(N^3)
int largest_SubArrays_sum1(int arr[], int n)
{
    int largest_sum  = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarraysum = 0;
            // cout<<"("<<i<<","<<j<<"),";
            for (int k = i; k <= j; k++)
            {
                subarraysum += arr[k];
                // cout << arr[k] << ",";
            }
            //put a check is subarraysum > largest_sum
             largest_sum = max(largest_sum,subarraysum);
           
        }
       
    }
    return largest_sum;
}
//Prefix-Sum Approach O(N^2)
int largest_SubArrays_sum2(int arr[], int n)
{
    int prefix[n]={0};
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
            prefix[i] = prefix[i-1] + arr[i];
    }
    
    int largest_sum  = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarraysum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
            // cout<<"("<<i<<","<<j<<"),";
          
            //put a check is subarraysum > largest_sum
             largest_sum = max(largest_sum,subarraysum);
           
        }
       
    }
    return largest_sum;
}
//Kadane's Algorithm O(N)
int maximum_subarray_sum(int arr[],int n){
    int cs = 0;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        cs =  cs+arr[i];
        if(cs<0){
            cs = 0;
        }
        largest = max(largest,cs);
    }
    return largest;
    
}
int main()
{
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr) / sizeof(int);
    cout<<largest_SubArrays_sum1(arr,n);
    cout<<endl;
    cout<<largest_SubArrays_sum2(arr,n);
    cout<<endl;
    cout<<maximum_subarray_sum(arr,n);
    cout<<endl;

    return 0; 