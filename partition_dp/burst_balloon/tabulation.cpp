// { Driver Code Starts
//Initial Template for C++#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size()-2;
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>0;i--)
        {
            for(int j=i;j<=n;j++)
            {
                int cur,ans=0;
                for(int k=i;k<=j;k++)
                {
                    cur=nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans=max(ans,cur);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
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