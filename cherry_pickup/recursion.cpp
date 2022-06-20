#include<bits/stdc++.h>
using namespace std;

class Solution {
    int cherry(int i,int j1,int j2,vector<vector<int>>& grid)
    {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
            return -1e8;
        if(i==grid.size()-1)
        {
            if(j1==j2)
                return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        int maxi=0;
        for(int k=-1;k<=1;k++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(j1==j2)
                    maxi=max(maxi,grid[i][j1] + cherry(i+1,j1+k,j2+j,grid));
                else
                    maxi=max(maxi,grid[i][j1] + grid[i][j2] + cherry(i+1,j1+k,j2+j,grid));
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int c=grid[0].size();
        return cherry(0,0,c-1,grid);
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