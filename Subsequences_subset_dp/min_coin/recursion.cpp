// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int coin(int i,vector<int>nums,int t)
    {
        if(i==0)
        {
            if(t%nums[i]==0)
                return t/nums[i];
            return 1e9;
        }
        if(t==0)
            return 0;
        int pick=INT_MAX;
        if(nums[i]<=t)
            pick=1+coin(i,nums,t-nums[i]);
        int npick=coin(i-1,nums,t);
        return min(pick,npick);
    }
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
	    int ans=coin(n-1,nums,amount);
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