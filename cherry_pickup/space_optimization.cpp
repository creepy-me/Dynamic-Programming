#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int c=grid[0].size();
        int r=grid.size();
        vector<vector<int>> dp(c,vector<int>(c,0));
        for(int i=r-1;i>=0;i--)
        {
            vector<vector<int>> t(c,vector<int>(c,0));
            for(int j1=c-1;j1>=0;j1--)
            {
                for(int j2=c-1;j2>=0;j2--)
                {
                    if(i==r-1)
                    {
                        if(j1==j2)
                            t[j1][j2]=grid[i][j1];
                        else
                            t[j1][j2]=grid[i][j1]+grid[i][j2];
                        continue;
                    }
                    int maxi=0;
                    for(int k=-1;k<=1;k++)
                    {
                        for(int j=-1;j<=1;j++)
                        {
                            if(j1+k>=0 && j1+k<c && j2+j>=0 && j2+j<c)
                            {
                                if(j1==j2 )
                                    maxi=max(maxi,grid[i][j1] + dp[j1+k][j2+j]);
                                else
                                    maxi=max(maxi,grid[i][j1] + grid[i][j2] + dp[j1+k][j2+j]);
                            }
                        }
                    }
                    t[j1][j2]=maxi;
                }
            }
            dp=t;
        }
        return dp[0][c-1];
    }
};

int main() {

   vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();
  Solution ob;
  cout << ob.cherryPickup(matrix);
}