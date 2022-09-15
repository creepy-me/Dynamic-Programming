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
    int palindromicPartition(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int cost=0,mnpar=1e8;
            for(int k=i;k<n;k++)
            {
                if(ispal(i,k,s))
                {
                    cost=1+dp[k+1];
                    mnpar=min(mnpar,cost);
                }
            }
            dp[i]=mnpar;
        }
        return dp[0]-1;
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