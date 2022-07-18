//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
    //complete the function here
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<int> dp(n+1,0),tp(n+1,0);
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=n;i2++)
            {
                if(s[i1-1]==t[i2-1])
                    tp[i2]=1+dp[i2-1];
                else
                    tp[i2]=max(dp[i2],tp[i2-1]);
            }
            dp=tp;
        }
        return n-dp[n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends