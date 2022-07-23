//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int f(int i,int j,string& w1,string& w2)
    {
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(w1[i]==w2[j])
            return f(i-1,j-1,w1,w2);
        int a=1+f(i,j-1,w1,w2);//insert
        int b=1+f(i-1,j,w1,w2);//delete
        int c=1+f(i-1,j-1,w1,w2);//replace
        return min(a,min(b,c));
    }
public:
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        return f(n-1,m-1,w1,w2);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.minDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends