// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> dp(m,-1);
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0){
                    temp[i]=grid[i][j];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if(i>0)
                    up=dp[j];
                if(j>0)
                    left=temp[j-1];
                temp[j]=grid[i][j]+min(left,up);
            }
            dp=temp;
        }
        return dp[m-1];
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