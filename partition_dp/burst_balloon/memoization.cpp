// { Driver Code Starts
//Initial Template for C++#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cur,ans=0;
        for(int k=i;k<=j;k++)
        {
            cur=nums[i-1]*nums[k]*nums[j+1] + f(i,k-1,nums,dp) + f(k+1,j,nums,dp);
            ans=max(ans,cur);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size()-2;
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.maxCoins(arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends