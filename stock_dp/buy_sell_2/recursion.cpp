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

int f(int i, bool buy, vector<int> &v)
{
    if (i == v.size())
        return 0;
    if (buy)
    {
        return max(-v[i] + f(i + 1, 0, v), f(i + 1, 1, v));
    }
    else
        return max(v[i] + f(i + 1, 1, v), f(i + 1, 0, v));
}
int maxProfit(vector<int> &values)
{
    int n = values.size();

    return f(0, true, values);
}