#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    bool check(int i,int a[],int t)
    {
        if(t==0)
            return true;
        if(i==0)
            return a[0]==t;
        bool pick=false;
        if(a[i]<=t)
            pick=check(i-1,a,t-a[i]);
        bool npick=check(i-1,a,t);
        return pick||npick;
    }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int t=sum/2;
	    while(t)
	    {
	        if(check(n-1,arr,t))
	            return abs(sum-2*t);
	        t--;
	    }
	    return sum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends