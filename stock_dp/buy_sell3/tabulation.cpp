#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap < 3; cap++)
            {
                if (buy)
                    dp[i][buy][cap] = max(-p[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                else
                    dp[i][buy][cap] = max(p[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices);
}