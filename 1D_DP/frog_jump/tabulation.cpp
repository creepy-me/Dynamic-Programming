int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    dp[1]=0;
    dp[2]=abs(h[1]-h[0]);
    for(int i=3;i<=n;i++)
    {
        int lt=dp[i-1]+abs(h[i-1]-h[i-2]);
        int rt=dp[i-2]+abs(h[i-1]-h[i-3]);
        dp[i]=min(lt,rt);
    }
    return dp[n];
}