//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<double> dp(m+1,0); 
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[0]=1;
            for(int j=m;j>=1;j--)
            {
                if(s[i-1]==t[j-1]){
                    dp[j]+=dp[j-1];
                }
            }
        }
        return int(dp[m]);
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