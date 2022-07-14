// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++)
            dp[0][i]=price[0]*i;
        // for(int i=0;i<n;i++)
        //     dp[i][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int pick=-1;
                if(j>i)
                     pick=price[i]+dp[i][j-i-1];
                int npick=dp[i-1][j];
                dp[i][j]=max(pick,npick);
            }
        }
        return dp[n-1][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends