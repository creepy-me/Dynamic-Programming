// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<long long int> dp(n,0);
        for(int i=0;i<m;i++)
        {
            vector<long long int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0){
                    temp[i]=1;
                    continue;
                }
                long long int up=0,left=0;
                if(i>0)
                    up += dp[j];
                if(j>0)
                    left += temp[j-1];
                temp[j] = (up+left)%1000000007;
            }
            dp=temp;
        }
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends