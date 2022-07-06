// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
        
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=target;
        if(sum<0 || sum&1)
            return 0;
        sum/=2;
        vector<int> dp(sum+1,0);
        // for(int i=0;i<n;i++)
           //  dp[i][0]=1;
        if(nums[0]==0)
            dp[0]=2;
        else
            dp[0]=1;
        if(nums[0]!=0 && nums[0]<=sum)
            dp[nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            vector<int> tp(sum+1,0);
            for(int t=0;t<=sum;t++)
            {
                int pick=0;
                if(nums[i]<=t)
                    pick=dp[t-nums[i]];
                int npick=dp[t];
                tp[t]=pick+npick;
            }
            dp=tp;
        }
        return dp[sum];
        
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