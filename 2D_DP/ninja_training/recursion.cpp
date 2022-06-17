int nt(int d,int l,vector<vector<int>> p)
{
    if(d==0)
    {
        int mx=0;
        for(int i=0;i<3;i++)
        {
            if(i!=l)
                mx = max(mx,p[0][i]);
        }
        return mx;
    }
    int mx=0;
    for(int i=0;i<3;i++)
    {
        if(i!=l)
        {
            int pt = p[d][i] + nt(d-1,i,p);
            mx = max(mx,pt);
        }
    }
    return mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return nt(n-1,3,points);
}