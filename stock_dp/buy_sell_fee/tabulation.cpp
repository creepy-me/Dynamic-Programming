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

int maxProfit(vector<int> &p, int fee)
{
    int n = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = max(-p[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(p[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
    }
    return dp[0][1];
}