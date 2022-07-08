
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int i,int w,int val[],int wt[],vector<vector<int>>& dp)
    {
        if(w<=0)
            return dp[i][w]=0;
        if(i==0)
        {
                return w/wt[0]*val[0];
        }
        if(dp[i][w]!=-1)
            return dp[i][w];
        int pick=0;
        if(wt[i]<=w)
            pick=val[i] + f(i,w-wt[i],val,wt,dp);
        int npick=f(i-1,w,val,wt,dp);
        return dp[i][w]=max(pick,npick);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        int ans=f(n-1,w,val,wt,dp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends