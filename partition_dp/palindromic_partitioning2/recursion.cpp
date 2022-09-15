//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispal(string s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int j,string s)
    {
        if(i==j)
            return 0;
        string t="";
        int cost=0,mnpar=1e8;
        for(int k=i;k<j;k++)
        {
            t+=s[k];
            if(ispal(t))
            {
                cost=1+f(k+1,j,s);
                mnpar=min(mnpar,cost);
            }
        }
        return mnpar;
    }
    int palindromicPartition(string s)
    {
        // code here
        int n=s.length();
        return f(0,n,s)-1;
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