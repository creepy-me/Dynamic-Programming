//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int f(int i,int l,vector<int>& nums)
    {
        if(i<0)
            return 0;
        int pick=0;
        int npick=f(i-1,l,nums);
        if(nums[i]<l)
        {
            pick=1+f(i-1,nums[i],nums);
        }
        return max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,INT_MAX,nums);
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