// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int sol(int i,int wt[],int val[],int w,vector<vector<int>>& dp)
    {
        if(i==0)
            return dp[0][w]=(w>=wt[0])?val[0]:0;
        if(w==0)
            return dp[i][w]=0;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int pick=0;
        if(w>=wt[i])
            pick=val[i] + sol(i-1,wt,val,w-wt[i],dp);
        int npick=sol(i-1,wt,val,w,dp);
        return dp[i][w]=max(pick,npick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return sol(n-1,wt,val,w,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends