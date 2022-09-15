//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool ispal(int i,int j,string& s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int j,string s,vector<int>& dp)
    {
        if(i==j)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int cost=0,mnpar=1e8;
        for(int k=i;k<j;k++)
        {
            if(ispal(i,k,s))
            {
                cost=1+f(k+1,j,s,dp);
                mnpar=min(mnpar,cost);
            }
        }
        return dp[i]=mnpar;
    }
    int palindromicPartition(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends