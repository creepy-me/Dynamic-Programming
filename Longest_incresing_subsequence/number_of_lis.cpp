//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size(), ans = 0, maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (nums[i] > nums[j] && dp[i] == dp[j] + 1)
                    cnt[i] += cnt[j];
            }
            maxi = max(maxi, dp[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
                ans += cnt[i];
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
        cout << ob.findNumberOfLIS(nums) << endl;
    }
}

// } Driver Code Ends