//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int i,int j,int arr[])
    {
        if(i==j)
            return 0;
        int steps,mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            steps=arr[i-1]*arr[k]*arr[j] + mcm(i,k,arr) + mcm(k+1,j,arr);
            mini=min(mini,steps);
        }
        return mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        return mcm(1,n-1,arr);
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