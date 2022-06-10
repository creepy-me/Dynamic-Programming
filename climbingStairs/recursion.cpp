// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int climbStairs(int n) {
        if(n<=1)
            return 1;
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
        return left + right;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.climbStairs(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends