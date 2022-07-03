// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
	    vector<int> dp(amount+1,0);
	    for(int i=0;i<=amount;i++){
	        if(i%nums[0]==0)
	            dp[i]=i/nums[0];
	        else
	            dp[i]=1e9;
	    }
	    for(int i=1;i<n;i++)
	    {
	        vector<int> tp(amount+1,0);
	        for(int t=1;t<=amount;t++)
	        {
	            int pick=INT_MAX;
                if(nums[i]<=t)
                    pick=1+tp[t-nums[i]];
                int npick=dp[t];
                tp[t] = min(pick,npick);
	        }
	        dp=tp;
	    }
	    return dp[amount]<1e9?dp[amount]:-1;
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