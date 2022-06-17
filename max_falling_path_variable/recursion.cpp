// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
    int f(vector<vector<int>> matrix,int i,int j)
    {
        int n = matrix.size();
        if(j<0 || j>=n)
            return INT_MIN;
        if(i==0)
            return matrix[i][j];
        int up = f(matrix,i-1,j);
        int left = f(matrix,i-1,j-1);
        int right = f(matrix,i-1,j+1);
        return matrix[i][j] + max(up,max(left,right));
    }
public:
    int maximumPath(int n,vector<vector<int>> matrix) {
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,f(matrix,n-1,i));
        }
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