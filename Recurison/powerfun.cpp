#include <bits/stdc++.h>
using namespace std;
int power(int a, int n)
{

    if (n == 0)
    {
        return 1;
    }
    return a * power(a, n - 1);
}
int poweroptimised(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int subProb = poweroptimised(a, n / 2);
    int subProbsq = subProb * subProb;
    if (n & 1)
    {
        return a * subProbsq;
    }
    return subProbsq;
}
int main()
{
    int a, n;
    cin >> a >> n;
    // cout << power(a, n) << endl;
    cout << poweroptimised(a, n) << endl;
    return 0;
}