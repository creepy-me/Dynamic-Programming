//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
int mod=1003;
class Solution{
public:
    int f(int i,int j,string s,bool e,vector<vector<vector<int>>>& dp)
    {
        if(i>j)
            return 0;
        if(i==j)
        {
            if(e)
                return s[i]=='T'?1:0;
            else
                return s[i]=='F'?1:0;
        }
        if(dp[i][j][e]!=-1)
            return dp[i][j][e];
        int ways=0;
        for(int k=i+1;k<j;k+=2)
        {
            // ways=0;
            int t1,t2,f1,f2;
            t1=f(i,k-1,s,1,dp);
            f1=f(i,k-1,s,0,dp);
            t2=f(k+1,j,s,1,dp);
            f2=f(k+1,j,s,0,dp);
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
        return dp[i][j][e]=ways;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,s,1,dp);
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