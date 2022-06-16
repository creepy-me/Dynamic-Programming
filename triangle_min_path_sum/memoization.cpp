#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(vector<vector<int>>& t,int i,int j,vector<vector<int>>& dp)
    {
        if(i==t.size()-1)
            return dp[i][j]=t[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d=f(t,i+1,j,dp);
        int dg=f(t,i+1,j+1,dp);
        return dp[i][j]=t[i][j] + min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        return f(t,0,0,dp);
    }
};

int main()
{
	vector<vector<int> > A{ { 2 },
							{ 3, 9 },
							{ 1, 6, 7 } };
	Solution ob;
	cout << ob.minimumTotal(A);
	return 0;
}
