// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int maximumPath(int n,vector<vector<int>> matrix) {
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0){
                    dp[i][j]=matrix[i][j];
                    continue;
                }
                int up=INT_MIN,left=INT_MIN,right=INT_MIN;
                up=dp[i-1][j];
                if(j>0)
                    left = dp[i-1][j-1];
                if(j<n-1)
                    right = dp[i-1][j+1];
                dp[i][j]=matrix[i][j] + max(up,max(left,right));
            }
        }
        for(int i=0;i<n;i++)
            ans=max(ans,dp[n-1][i]);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends