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
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0){
                    temp[j]=matrix[i][j];
                    continue;
                }
                int up=INT_MIN,left=INT_MIN,right=INT_MIN;
                up=dp[j];
                if(j>0)
                    left = dp[j-1];
                if(j<n-1)
                    right = dp[j+1];
                temp[j]=matrix[i][j] + max(up,max(left,right));
            }
            dp=temp;
        }
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
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