class Solution {
    int path(vector<vector<int>> &a,int n,int m,vector<vector<int>> &dp)
    {
        if(n>=0 && m>=0 && a[n][m]==1)
            return dp[n][m]=0;
        if(n==0 && m==0)
            return dp[0][0]=1;
        if(n<0 || m<0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        int up = path(a,n-1,m,dp);
        int left = path(a,n,m-1,dp);
        return dp[n][m]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m = a[0].size();
        if(a[0][0]==1 || a[n-1][m-1]==1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(a,n-1,m-1,dp);
    }
};