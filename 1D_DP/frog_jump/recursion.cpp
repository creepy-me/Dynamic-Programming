int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    if(n==1)
        return 0;
    if(n==2)
        return abs(h[1]-h[0]);
    int lt=frogJump(n-1,h)+abs(h[n-1]-h[n-2]);
    int rt=frogJump(n-2,h)+abs(h[n-1]-h[n-3]);
    return min(lt,rt);
}