int ninjaTraining(int n, vector<vector<int>> &p)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,0));
    for(int l=0;l<=3;l++)
    {
        int mx=0;
        for(int i=0;i<3;i++)
        {
            if(i!=l)
                mx = max(mx,p[0][i]);
        }
        dp[0][l]=mx;
    }
    for(int d=1;d<n;d++)
    {
        for(int l=0;l<=3;l++)
        {
            int mx=0;
            for(int i=0;i<3;i++)
            {
                if(i!=l)
                {
                    int pt = p[d][i] + dp[d-1][i];
                    mx = max(mx,pt);
                }
            }
            dp[d][l]=mx;
        }
    }
    return dp[n-1][3];
}