#include <bits/stdc++.h>
using namespace std;
// top-down DP approach
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