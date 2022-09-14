#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int f(int i,int j,string s,bool e)
    {
        if(i>j)
            return 0;
        if(i==j)
        {
            if(e)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        int ways=0;
        for(int k=i+1;k<j;k+=2)
        {
            // ways=0;
            int t1,t2,f1,f2;
            t1=f(i,k-1,s,1);
            f1=f(i,k-1,s,0);
            t2=f(k+1,j,s,1);
            f2=f(k+1,j,s,0);
            if(s[k]=='&')
            {
                if(e)
                    ways+= t1*t2;
                else
                    ways+=t1*f2 + t2*f1 + f1*f2;
            }
            else if(s[k]=='|')
            {
                if(e)
                    ways+= t1*t2 + t1*f2 + t2*f1;
                else
                    ways+=f1*f2;
            }
            else
            {
                if(e)
                    ways+= t1*f2 + t2*f1;
                else
                    ways+=t1*t2 + f1*f2;
            }
            ways%=1003;
        }
        return ways;
    }
    int countWays(int n, string s){
        // code here
        return f(0,n-1,s,1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends