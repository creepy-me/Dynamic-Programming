int nt(int d,int l,vector<vector<int>> &p,vector<vector<int>> &dp)
{
    if(dp[d][l]!=-1)
        return dp[d][l];
    if(d==0)
    {
        int mx=0;
        for(int i=0;i<3;i++)
        {
            if(i!=l)
                mx = max(mx,p[0][i]);
        }
        return dp[d][l]=mx;
    }
    int mx=0;
    for(int i=0;i<3;i++)
    {
        if(i!=l)
        {
            int pt = p[d][i] + nt(d-1,i,p,dp);
            mx = max(mx,pt);
        }
    }
    return dp[d][l]=mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return nt(n-1,3,points,dp);
}