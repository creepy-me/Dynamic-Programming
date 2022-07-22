//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
    int f(int i,string& s,int j,string& t)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(s[i]==t[j])
            return f(i-1,s,j-1,t)+f(i-1,s,j,t);
        else
            return f(i-1,s,j,t);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        return f(n-1,s,m-1,t);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.numDistinct(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends