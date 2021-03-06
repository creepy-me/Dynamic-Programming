class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m = a[0].size();
        if(a[0][0]==1 || a[n-1][m-1]==1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                    continue;
                if(a[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0)
                    up += dp[i-1][j];
                if(j>0)
                    left += dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[n-1][m-1];
    }
};