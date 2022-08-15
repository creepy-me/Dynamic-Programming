//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=max(1+dp[j],dp[i]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
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