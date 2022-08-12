//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int f(int i,int l,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i<0)
            return 0;
        if(dp[i][l]!=-1)
            return dp[i][l];
        int pick=0;
        int npick=f(i-1,l,nums,dp);
        if(l==nums.size()||nums[i]<nums[l])
        {
            pick=1+f(i-1,i,nums,dp);
        }
        return dp[i][l]=max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,nums,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        vector<int> nums(n);
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>nums[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.lengthOfLIS(nums) << endl;
    }
}

// } Driver Code Ends