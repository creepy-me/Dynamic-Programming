//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod=1003;
class Solution{
public:
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                for(int e=0;e<2;e++){
                if(i==j)
                {
                    if(e)
                    dp[i][j][e]=(s[i]=='T'?1:0);
                    else
                    dp[i][j][e]=(s[i]=='F'?1:0);
                    continue;
                }
                int ways=0;
                for(int k=i+1;k<j;k+=2)
                {
                    // ways=0;
                    int t1,t2,f1,f2;
                    t1=dp[i][k-1][1];
                    f1=dp[i][k-1][0];
                    t2=dp[k+1][j][1];
                    f2=dp[k+1][j][0];
                    if(s[k]=='&')
                    {
                        if(e)
                            ways+= (t1*t2)%mod;
                        else
                            ways+=(t1*f2)%mod + (t2*f1)%mod + (f1*f2)%mod;
                    }
                    else if(s[k]=='|')
                    {
                        if(e)
                            ways+= (t1*t2)%mod + (t1*f2)%mod + (t2*f1)%mod;
                        else
                            ways+=(f1*f2)%mod;
                    }
                    else
                    {
                        if(e)
                            ways+= (t1*f2)%mod + (t2*f1)%mod;
                        else
                            ways+=(t1*t2)%mod + (f1*f2)%mod;
                    }
                    ways%=mod;
                }
                dp[i][j][e]=ways;
                }
            }
        }
        return dp[0][n-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends