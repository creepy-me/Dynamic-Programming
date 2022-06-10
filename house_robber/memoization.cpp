  #include<bits/stdc++.h>
using namespace std;

class Solution {
    int robber(vector<int> &nums,int i,int j,vector<int> &dp)
    {
        if(i==j)
            return dp[i]=nums[i];
        if(dp[i]!=-1)
            return dp[i];
        int pick = nums[i];
        int npick=0;
        if(i>j+1)
            pick += robber(nums,i-2,j,dp);
        if(i>j)
        npick += robber(nums,i-1,j,dp);
        return dp[i]=max(pick,npick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        int ans1=robber(nums,n-1,1,dp);
        dp.assign(n,-1);
        int ans2=robber(nums,n-2,0,dp);
        return max(ans1,ans2);
    }
};

main(){
   vector<int> v = {1,2,3,5};
   Solution ob;
   cout << ob.rob(v);
}