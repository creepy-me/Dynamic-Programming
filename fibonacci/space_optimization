// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int fib(int n) {
        if(n<=1)
            return n;
        int cur,prev=1,prev2=0;
        for(int i=2;i<=n;i++){
            cur = prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
         int n;
        cin >> n;
        Solution ob;
        cout << fib(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends