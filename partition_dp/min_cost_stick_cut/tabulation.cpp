//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int t=cuts.size();
        vector<vector<int>> dp(t,vector<int>(t,0));
        for(int i=t-2;i>0;i--)
        {
            for(int j=i;j<t-1;j++)
            {
                int cost,ans=INT_MAX;
                for(int id=i;id<=j;id++)
                {
                    cost=cuts[j+1]-cuts[i-1] + dp[i][id-1] + dp[id+1][j];
                    ans=min(ans,cost);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][t-2];
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