//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=0;
                else
                {
                    int steps,mini=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                        mini=min(mini,steps);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends