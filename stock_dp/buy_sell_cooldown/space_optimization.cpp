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

int maxProfit(vector<int> &p)
{
    int n = p.size();
    vector<int> cur(2, 0), f1(2, 0), f2(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        cur[1] = max(-p[i] + f1[0], f1[1]);
        cur[0] = max(p[i] + f2[1], f1[0]);
        f2 = f1;
        f1 = cur;
    }
    return f1[1];
}