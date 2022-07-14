// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++)
            dp[i]=price[0]*i;
        for(int i=1;i<n;i++)
        {
            vector<int> tp(n+1,0);
            for(int j=0;j<=n;j++)
            {
                int pick=-1;
                if(j>i)
                     pick=price[i]+tp[j-i-1];
                int npick=dp[j];
                tp[j]=max(pick,npick);
            }
            dp=tp;
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends