// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
    long long int nop(int m,int n,vector<vector<long long int>> &dp)
    {
        if(m==0 && n==0)
            return dp[m][n]=1;
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        long long int up = nop(m-1,n,dp)%1000000007;
        long long int left = nop(m,n-1,dp)%1000000007;
        return dp[m][n]=(up+left)%1000000007;
    }
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long int>> dp(m,vector<long long int>(n,-1));
        return nop(m-1,n-1,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends