#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    bool check(int i,int a[],int t,vector<vector<int>>& dp)
    {
        if(t==0)
            return true;
        if(i==0)
            return dp[i][t]=a[0]==t;
        if(dp[i][t]!=-1)
            return dp[i][t];
        bool pick=false;
        if(a[i]<=t)
            pick=check(i-1,a,t-a[i],dp);
        bool npick=check(i-1,a,t,dp);
        return dp[i][t]=pick||npick;
    }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int t=sum/2;
	    vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
	    while(t)
	    {
	        if(check(n-1,arr,t,dp))
	            return abs(sum-2*t);
	        t--;
	    }
	    return sum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends