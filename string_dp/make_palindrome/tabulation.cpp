//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
    //complete the function here
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=n;i2++)
            {
                if(s[i1-1]==t[i2-1])
                    dp[i1][i2]=1+dp[i1-1][i2-1];
                else
                    dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        return n-dp[n][n];
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