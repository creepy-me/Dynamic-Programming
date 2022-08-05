#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> dp(2, vector<int>(3, 0)), tp(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap < 3; cap++)
            {
                if (buy)
                    tp[buy][cap] = max(-p[i] + dp[0][cap], dp[1][cap]);
                else
                    tp[buy][cap] = max(p[i] + dp[1][cap - 1], dp[0][cap]);
            }
        }
        dp = tp;
    }
    return dp[1][2];
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices);
}