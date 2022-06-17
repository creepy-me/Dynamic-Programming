#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> dp;
        for(int i=n-1;i>=0;i--)
        {
            vector<int> temp(i+1,0);
            for(int j=i;j>=0;j--)
            {
                if(i==n-1)
                {
                    temp[j] = t[i][j];
                    continue;
                }
                int d = dp[j];
                int dg = dp[j+1];
                temp[j] = t[i][j] + min(d,dg);
            }
            dp=temp;
        }
        return dp[0];
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
