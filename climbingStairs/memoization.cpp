// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int memo(int n,vector<int> &dp)
    {
        if(n<=1)
            return 1;
        if(dp[n])
            return dp[n];
        int left = memo(n-1,dp);
        int right = memo(n-2,dp);
        dp[n]=left+right;
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return memo(n,dp);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.climbStairs(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends