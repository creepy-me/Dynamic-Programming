// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int i,int price[],int n)
    {
        if(n==0)
            return 0;
        if(i==0)
            return price[0]*n;
        int pick=0;
        if(n>i)
            pick=price[i]+f(i,price,n-i-1);
        int npick=f(i-1,price,n);
        return max(pick,npick);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        //int m=price.size();
        return f(n-1,price,n);
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