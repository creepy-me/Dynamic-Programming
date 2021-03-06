// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int fib(int n) {
        if(n<=1)
            return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
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