#include <bits/stdc++.h>
using namespace std;
// top-down DP approach
/**
 * We are trying to find the maximum profit that can be earned by selling wines from left to right. 
 * 
 * The function is called with the following parameters: 
 * 
 * - dp: A 2D array that stores the results of subproblems. 
 * - prices: An array that stores the price of wines. 
 * - L: Starting index of the segment of wines that must be sold. 
 * - R: Ending index of the segment of wines that must be sold. 
 * - y: The current year. 
 * 
 * The function returns the maximum profit that can be earned by selling wines from index L to index R.
 * 
 * 
 * The function is called with L = 0, R = n - 1, and y = 1. 
 * 
 * The base case is when L > R. In this case, no wines are left to sell, so the profit is 0. 
 * 
 * If the result of the subproblem is already stored
 * 
 * @param dp The dp array
 * @param prices array of prices of wines
 * @param L Left index of the array
 * @param R The rightmost index of the array.
 * @param y year
 * 
 * @return The maximum profit that can be earned by selling the wines.
 */
int wines(int dp[][10], int prices[], int L, int R, int y)
{
    if (L > R)
        return 0;
    if (dp[L][R] != 0)
        return dp[L][R];
    int pick_left = y * prices[L] + wines(dp, prices, L + 1, R, y + 1);
    int pick_right = y * prices[R] + wines(dp, prices, L, R - 1, y + 1);
    return dp[L][R] = max(pick_left, pick_right);
}
/**
 * We start from the bottom of the matrix and fill the matrix row by row.
 * 
 * @param prices an array of prices of wines
 * @param n number of wines
 * 
 * @return The maximum profit that can be earned by selling the wines.
 */
int wines_bottom_app(int prices[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                dp[i][j] = n*prices[i];
            }
            else if (i < j)
            {
                int year = n - (j - i);
                int pick_left = prices[i] * year + dp[i + 1][j];
                int pick_right = prices[j] * year + dp[i][j - 1];
                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n - 1];
}
int main()
{
    int arr[] = {2, 3, 5, 1, 4};
    int n = 5;
    int dp[10][10] = {0};
    cout << wines(dp, arr, 0, n - 1, 1) << endl;
    cout << wines_bottom_app(arr, n) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}