#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1)
                {
                    dp[i][j] = t[i][j];
                    continue;
                }
                int d = dp[i+1][j];
                int dg = dp[i+1][j+1];
                dp[i][j] = t[i][j] + min(d,dg);
            }
        }
        return dp[0][0];
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
