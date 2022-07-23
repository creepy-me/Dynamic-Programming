//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int i=0;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(w1[i-1]==w2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    int a=1+dp[i][j-1];//insert
                    int b=1+dp[i-1][j];//delete
                    int c=1+dp[i-1][j-1];//replace
                    dp[i][j]=min(a,min(b,c));
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.minDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends