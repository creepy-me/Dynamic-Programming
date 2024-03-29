//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int f(int i,int j,vector<int>& cuts)
    {
        if(i>j)
            return 0;
        int cost,ans=INT_MAX;
        for(int id=i;id<=j;id++)
        {
            cost=cuts[j+1]-cuts[i-1] + f(i,id-1,cuts) + f(id+1,j,cuts);
            ans=min(ans,cost);
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int t=cuts.size();
        return f(1,t-2,cuts);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,n;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>n;
        Solution ob;
        cout<<ob.minCost(n, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends