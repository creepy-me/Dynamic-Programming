// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int fibdp(int n,vector<int> &dp) {
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        dp[n] = fibdp(n-1,dp)+fibdp(n-2,dp);
        return dp[n];
    }
    int fib(int n)
    {
        vector<int> dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;
        return fibdp(n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
         int n;
        cin >> n;
        Solution ob;
        cout << fib(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends