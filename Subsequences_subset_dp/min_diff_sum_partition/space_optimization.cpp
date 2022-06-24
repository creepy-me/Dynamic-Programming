// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int t=sum/2;
	    vector<bool> dp(t+1,false);
	    dp[0]=true;
	    if(arr[0]<=t)
	        dp[arr[0]]=true;
	    for(int i=1;i<n;i++)
	    {
	        vector<bool> tp(t+1,true);
	        for(int j=1;j<=t;j++)
	        {
	            bool pick=false;
                if(arr[i]<=j)
                    pick=dp[j-arr[i]];
                bool npick=dp[j];
                tp[j]=pick||npick;
	        }
	        dp=tp;
	    }
	    while(!dp[t])
	        t--;
	    return abs(sum-2*t);
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