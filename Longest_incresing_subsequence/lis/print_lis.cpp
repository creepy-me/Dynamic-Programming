//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0,ind=0;
        vector<int> dp(n,1),hash(n,0);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>ans)
            {
                ind=i;
                ans=dp[i];
            }
        }
        vector<int> lis;
        lis.push_back(nums[ind]);
        while(hash[ind]!=ind)
        {
            ind=hash[ind];
            lis.push_back(nums[ind]);
        }
        reverse(lis.begin(),lis.end());
        for(auto x:lis)
            cout<<x<<" ";
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