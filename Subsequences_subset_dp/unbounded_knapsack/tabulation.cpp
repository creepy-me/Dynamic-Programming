// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i=W;i>=wt[0];i--)
            dp[0][i]=i/wt[0]*val[0];
        for(int i=1;i<n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                int pick=0;
                if(wt[i]<=w)
                    pick=val[i]+dp[i][w-wt[i]];
                int npick=dp[i-1][w];
                dp[i][w]=max(pick,npick);
            }
        }
        return dp[n-1][W];
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