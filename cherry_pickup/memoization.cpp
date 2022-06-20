#include<bits/stdc++.h>
using namespace std;

class Solution {
    int cherry(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
            return -1e8;
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        if(i==grid.size()-1)
        {
            if(j1==j2)
                return dp[i][j1][j2]=grid[i][j1];
            return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        int maxi=0;
        for(int k=-1;k<=1;k++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(j1==j2)
                    maxi=max(maxi,grid[i][j1] + cherry(i+1,j1+k,j2+j,grid,dp));
                else
                    maxi=max(maxi,grid[i][j1] + grid[i][j2] + cherry(i+1,j1+k,j2+j,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int c=grid[0].size();
        int r=grid.size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return cherry(0,0,c-1,grid,dp);
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