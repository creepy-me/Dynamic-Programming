#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int t=sum/2;
	    vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));
	    for(int i=0;i<n;i++)
	        dp[i][0]=true;
	    if(arr[0]<=t)
	        dp[0][arr[0]]=true;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<=t;j++)
	        {
	            bool pick=false;
                if(arr[i]<=j)
                    pick=dp[i-1][j-arr[i]];
                bool npick=dp[i-1][j];
                dp[i][j]=pick||npick;
	        }
	    }
	    while(!dp[n-1][t])
	        t--;
	    return sum-2*t;
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