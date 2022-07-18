//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int lcs(int i1,string& s,int i2,string& t,vector<vector<int>>& dp)
	{
	    if(i1==0 || i2==0)
	        return 0;
	    if(dp[i1][i2]!=-1)
	        return dp[i1][i2];
	    if(s[i1-1]==t[i2-1])
	        return dp[i1][i2]=1+lcs(i1-1,s,i2-1,t,dp);
	    return dp[i1][i2]=max(lcs(i1-1,s,i2,t,dp),lcs(i1,s,i2-1,t,dp));
	}
	public:
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    int n=s.length(),m=t.length();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	    return n+m-2*lcs(n,s,m,t,dp);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends