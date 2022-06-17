// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    int mps(vector<vector<int>>& grid,int i,int j)
    {
        if(i==0 && j==0)
            return grid[i][j];
        if(i<0 || j<0)
            return INT_MAX;
        int up = mps(grid,i-1,j);
        int left = mps(grid,i,j-1);
        return grid[i][j] + min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return mps(grid,n-1,m-1);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minPathSum(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends