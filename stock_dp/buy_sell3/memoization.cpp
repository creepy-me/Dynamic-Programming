#include <bits/stdc++.h>

using namespace std;

int f(int i, bool buy, int cap, vector<int> &p, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;
    if (i == p.size())
        return 0;
    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
    if (buy)
        return dp[i][buy][cap] = max(-p[i] + f(i + 1, 0, cap, p, dp), f(i + 1, 1, cap, p, dp));
    else
        return dp[i][buy][cap] = max(p[i] + f(i + 1, 1, cap - 1, p, dp), f(i + 1, 0, cap, p, dp));
}
int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, p, dp);
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices);
}