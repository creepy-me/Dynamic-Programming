int ninjaTraining(int n, vector<vector<int>> &p)
{
    // Write your code here.
    vector<int> dp(4,0);
    for(int l=0;l<=3;l++)
    {
        int mx=0;
        for(int i=0;i<3;i++)
        {
            if(i!=l)
                mx = max(mx,p[0][i]);
        }
        dp[l]=mx;
    }
    for(int d=1;d<n;d++)
    {
        vector<int> temp(4,0);
        for(int l=0;l<=3;l++)
        {
            int mx=0;
            for(int i=0;i<3;i++)
            {
                if(i!=l)
                {
                    int pt = p[d][i] + dp[i];
                    mx = max(mx,pt);
                }
            }
            temp[l]=mx;
        }
        dp=temp;
    }
    return dp[3];
}