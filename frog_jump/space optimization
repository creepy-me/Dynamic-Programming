int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    if(n==1)
        return 0;
    int cur,prev2=0;
    int prev=abs(h[1]-h[0]);
    for(int i=3;i<=n;i++)
    {
        int lt=prev+abs(h[i-1]-h[i-2]);
        int rt=prev2+abs(h[i-1]-h[i-3]);
        cur=min(lt,rt);
        prev2=prev;
        prev=cur;
    }
    return prev;
}