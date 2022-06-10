int fj(int n,vector<int> &h,vector<int> &dp)
{
    if(n==1)
        return dp[n]=0;
    if(n==2)
        return dp[n]=abs(h[1]-h[0]);
    if(dp[n]!=-1)
        return dp[n];
    int lt=fj(n-1,h,dp)+abs(h[n-1]-h[n-2]);
    int rt=fj(n-2,h,dp)+abs(h[n-1]-h[n-3]);
    return dp[n]=min(lt,rt);
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return fj(n,h,dp);
}