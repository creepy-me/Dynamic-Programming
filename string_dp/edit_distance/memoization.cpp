//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int f(int i,int j,string& w1,string& w2,vector<vector<int>>& dp)
    {
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(w1[i]==w2[j])
            return dp[i][j]=f(i-1,j-1,w1,w2,dp);
        int a=1+f(i,j-1,w1,w2,dp);//insert
        int b=1+f(i-1,j,w1,w2,dp);//delete
        int c=1+f(i-1,j-1,w1,w2,dp);//replace
        return dp[i][j]=min(a,min(b,c));
    }
public:
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,w1,w2,dp);
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