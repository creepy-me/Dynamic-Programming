//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<int> dp(m+1,0),tp(m+1,0);
        for(int i=0;i<=m;i++)
            dp[i]=i;
        for(int i=1;i<=n;i++)
        {
            tp[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(w1[i-1]==w2[j-1])
                    tp[j]=dp[j-1];
                else
                {
                    int a=1+tp[j-1];//insert
                    int b=1+dp[j];//delete
                    int c=1+dp[j-1];//replace
                    tp[j]=min(a,min(b,c));
                }
            }
            dp=tp;
        }
        return dp[m];
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