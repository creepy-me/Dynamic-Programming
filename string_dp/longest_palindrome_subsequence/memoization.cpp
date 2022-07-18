//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int lcs(int i1,string& s,int i2,string& t,vector<vector<int>>& dp)
    {
        if(i1<0||i2<0)
            return 0;
        if(s[i1]==t[i2])
            return dp[i1][i2]=1+lcs(i1-1,s,i2-1,t,dp);
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        return dp[i1][i2]=max(lcs(i1-1,s,i2,t,dp),lcs(i1,s,i2-1,t,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return lcs(n-1,s,n-1,t,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalindromeSubseq(s) << endl;
    }
}

// } Driver Code Ends