//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    int n=s.length(),m=t.length();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    for(int i1=1;i1<=n;i1++)
	    {
	        for(int i2=1;i2<=m;i2++)
	        {
	            if(s[i1-1]==t[i2-1])
        	        dp[i1][i2]=1+dp[i1-1][i2-1];
        	    else
        	        dp[i1][i2]=max(dp[i1][i2-1],dp[i1-1][i2]);
	        }
	    }
	    return n+m-2*dp[n][m];
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