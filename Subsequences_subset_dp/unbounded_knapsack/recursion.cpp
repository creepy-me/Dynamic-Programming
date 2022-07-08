// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int i,int w,int val[],int wt[])
    {
        if(w==0)
            return 0;
        if(i==0)
        {
            if(wt[0]<=w)
                return w/wt[0];
            return 0;
        }
        int pick=0;
        if(wt[i]<=w)
            pick=max(pick,val[i] + f(i,w-wt[i],val,wt));
        int npick=f(i-1,w,val,wt);
        return max(pick,npick);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        return f(n-1,w,val,wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends