//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
int maxProfit(vector<int> &v);

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, i;
        cin >> n;
        vector<int> prices(n);
        for (i = 0; i < n; i++)
            cin >> prices[i];
        // function call
        cout << maxProfit(prices);
    }
    return 0;
}

// } Driver Code Ends

// User function template for C++

// This function finds the buy sell schedule for maximum profit
int maxProfit(vector<int> &v)
{
    int n = v.size();
    int cur = 0, cur2 = 0, prev = 0, prev2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j)
            {
                cur = max(-v[i] + prev2, prev);
            }
            else
                cur2 = max(v[i] + prev, prev2);
            prev = cur;
            prev2 = cur2;
        }
    }
    return (prev);
}