//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int n,int k,vector<int>& arr)
    {
        if(i==n)
            return 0;
        int ans=-1,maxi=-1,sum=0,t=0;
        for(int x=i;x<min(i+k,n);x++)
        {
            t++;
            maxi=max(maxi,arr[x]);
            sum = maxi*t + f(x+1,n,k,arr);
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        return f(0,n,k,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxSumAfterPartitioning(arr,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends