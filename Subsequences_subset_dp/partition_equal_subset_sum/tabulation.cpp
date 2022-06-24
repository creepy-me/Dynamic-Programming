// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(nums[0]<=sum/2)
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=sum/2;t++)
            {
                bool pick=false;
                if(nums[i]<=t)
                pick = dp[i-1][t-nums[i]];
                bool npick = dp[i-1][t];
                dp[i][t]=(pick||npick);
            }
        }
        return dp[n-1][sum/2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N,0);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.canPartition(arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends