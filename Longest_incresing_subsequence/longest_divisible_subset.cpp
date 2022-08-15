//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), l = 0, res = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, 0), ans;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > res)
            {
                res = dp[i];
                l = i;
            }
        }
        // int i=hash[l];
        ans.push_back(nums[l]);
        while (l != hash[l])
        {
            l = hash[l];
            ans.push_back(nums[l]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        vector<int> nums(n);

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        // calling method longestSubsequence()
        vector<int> ans=ob.largestDivisibleSubset(nums);
        for(auto x:ans)
        {
            cout<<x<<"\n";
        }
    }
}

// } Driver Code Ends