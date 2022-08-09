//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
int maxProfit(vector<int> &v, int fee);

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, i, fee;
        cin >> n >> fee;
        vector<int> prices(n);
        for (i = 0; i < n; i++)
            cin >> prices[i];
        // function call
        cout << maxProfit(prices, fee);
    }
    return 0;
}

// } Driver Code Ends

// User function template for C++

// This function finds the buy sell schedule for maximum profit

int f(int i, int buy, vector<int> &p, int fee, vector<vector<int>> &dp)
{
    if (i >= p.size())
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    if (buy)
        return dp[i][buy] = max(-p[i] + f(i + 1, 0, p, fee, dp), f(i + 1, 1, p, fee, dp));
    else
        return dp[i][buy] = max(p[i] + f(i + 1, 1, p, fee, dp) - fee, f(i + 1, 0, p, fee, dp));
}
int maxProfit(vector<int> &p, int fee)
{
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, p, fee, dp);
}