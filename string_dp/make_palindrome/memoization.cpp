//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int lps(int i1,string& s,int i2,string& t,vector<vector<int>>& dp)
    {
        if(i1==0 || i2==0)
            return 0;
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(s[i1-1]==t[i2-1])
            return dp[i1][i2]=1+lps(i1-1,s,i2-1,t,dp);
        return dp[i1][i2]=max(lps(i1-1,s,i2,t,dp),lps(i1,s,i2-1,t,dp));
    }
  public:
    int countMin(string s){
    //complete the function here
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return n-lps(n,s,n,t,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends