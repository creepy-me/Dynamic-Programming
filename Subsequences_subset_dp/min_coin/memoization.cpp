// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int coin(int i,vector<int>nums,int t,vector<vector<int>>& dp)
    {
        if(t==0)
            return dp[i][t]=0;
        if(i==0)
        {
            if(t%nums[i]==0)
                return dp[0][t]=t/nums[i];
            return dp[0][t]=1e9;
        }
        if(dp[i][t]!=-1)
            return dp[i][t];
        int pick=INT_MAX;
        if(nums[i]<=t)
            pick=1+coin(i,nums,t-nums[i],dp);
        int npick=coin(i-1,nums,t,dp);
        return dp[i][t] = min(pick,npick);
    }
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
	    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
	    int ans=coin(n-1,nums,amount,dp);
	    return ans<1e9?ans:-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends