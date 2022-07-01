// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int sol(int i,int wt[],int val[],int w)
    {
        if(i==0)
            return (w>=wt[0])?val[0]:0;
        if(w==0)
            return 0;
        int pick=0;
        if(w>=wt[i])
            pick=val[i] + sol(i-1,wt,val,w-wt[i]);
        int npick=sol(i-1,wt,val,w);
        return max(pick,npick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       return sol(n-1,wt,val,w);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends