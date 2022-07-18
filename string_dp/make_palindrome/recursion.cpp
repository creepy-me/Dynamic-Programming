//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int lps(int i1,string& s,int i2,string& t)
    {
        if(i1==0 || i2==0)
            return 0;
        if(s[i1-1]==t[i2-1])
            return 1+lps(i1-1,s,i2-1,t);
        return max(lps(i1-1,s,i2,t),lps(i1,s,i2-1,t));
    }
  public:
    int countMin(string s){
    //complete the function here
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        return n-lps(n,s,n,t);
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