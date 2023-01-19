#include<bits/stdc++.h>
using namespace std;
int knapSack_recu(int wts[],int prices[],int N,int W){
    if(N==0 or W==0) return 0;
    int inc = 0;
    int exc = 0;
    if(wts[N-1]<=W){
        inc = prices[N-1] + knapSack_recu(wts,prices,N-1,W-wts[N-1]);
    }
    exc = knapSack_recu(wts,prices,N-1,W);
    return max(inc,exc);
}
/**
 * For each item, we have two choices: either include it in the knapsack or exclude it from the
 * knapsack. 
 * 
 * We take the maximum of these two choices. 
 * 
 * The base case is when we have no items left or the knapsack's capacity becomes 0. 
 * 
 * In that case, the maximum value we can get is 0. 
 * 
 * The recurrence relation is: 
 * 
 * dp[n][w] = max(prices[n-1] + dp[n-1][w-wt[n-1]], dp[n-1][w])
 * 
 * The first term in the max function is the case when we include the current item in the knapsack. 
 * 
 * The second term is when we exclude the current item from the knapsack. 
 * 
 * The time complexity of the above solution is O(N*W) and the space complexity is O
 * 
 * @param wt array of weights of items
 * @param prices an array of prices of items
 * @param N Number of items
 * @param W Total weight of the knapsack
 * 
 * @return The maximum value that can be obtained by picking items from the given set of items.
 */
int knapSack_DP(int wt[],int prices[],int N,int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc = 0,exc = 0;
            if(wt[n-1]<=w){
                inc = prices[n-1] + dp[n-1][w-wt[n-1]];
            }
            exc = dp[n-1][w];
            dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][W];
}
int main()
{
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};
    int N = 4;
    int W = 11;
    cout<<knapSack_recu(wts,prices,N,W)<<endl;
    cout<<knapSack_DP(wts,prices,N,W)<<endl;
return 0;
}
