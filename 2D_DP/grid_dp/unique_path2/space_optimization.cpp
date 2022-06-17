class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m = a[0].size();
        if(a[0][0]==1 || a[n-1][m-1]==1)
            return 0;
        vector<int> dp(m,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0){
                    temp[i]=1;
                    continue;
                }
                if(a[i][j]==1)
                {
                    temp[j]=0;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0)
                    up += dp[j];
                if(j>0)
                    left += temp[j-1];
                temp[j]=up+left;
            }
            dp=temp;
        }
        return dp[m-1];
    }
};