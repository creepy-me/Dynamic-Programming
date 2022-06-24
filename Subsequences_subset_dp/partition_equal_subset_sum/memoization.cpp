// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    bool check(int i,vector<int>& a,int t,vector<vector<int>>& dp)
    {
        if(i==0)
            return dp[0][t]=(a[i]==t);
        if(t==0)
            return dp[i][0]=true;
        if(dp[i][t]!=-1)
            return dp[i][t];
        bool pick=false;
        if(a[i]<=t)
            pick = check(i-1,a,t-a[i],dp);
        bool npick = check(i-1,a,t,dp);
        return dp[i][t]=(pick||npick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return check(n-1,nums,sum/2,dp);
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