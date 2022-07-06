// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
    int f(int i,vector<int>& nums,int t,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(t==0 && nums[0]==0)
                return 2;
            if(t==0 || t==nums[0])
                return 1;
            return 0;
        }
        if(dp[i][t]!=-1)
            return dp[i][t];
        int pick=0;
        if(nums[i]<=t)
            pick=f(i-1,nums,t-nums[i],dp);
        int npick=f(i-1,nums,t,dp);
        return dp[i][t]=pick+npick;
    }
        
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=target;
        if(sum<0 || sum&1)
            return 0;
        sum/=2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,nums,sum,dp);
        
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends