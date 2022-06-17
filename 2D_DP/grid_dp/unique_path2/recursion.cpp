class Solution {
    int path(vector<vector<int>> &a,int n,int m)
    {
        if(n>=0 && m>=0 && a[n][m]==1)
            return 0;
        if(n==0 && m==0)
            return 1;
        if(n<0 || m<0)
            return 0;
        int up = path(a,n-1,m);
        int left = path(a,n,m-1);
        return up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m = a[0].size();
        if(a[0][0]==1 || a[n-1][m-1]==1)
            return 0;
        return path(a,n-1,m-1);
    }
};