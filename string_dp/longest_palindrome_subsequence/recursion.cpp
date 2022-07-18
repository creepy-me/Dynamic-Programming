//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int lcs(int i1,string& s,int i2,string& t)
    {
        if(i1<0||i2<0)
            return 0;
        if(s[i1]==t[i2])
            return 1+lcs(i1-1,s,i2-1,t);
        return max(lcs(i1-1,s,i2,t),lcs(i1,s,i2-1,t));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        return lcs(n-1,s,n-1,t);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalindromeSubseq(s) << endl;
    }
}

// } Driver Code Ends