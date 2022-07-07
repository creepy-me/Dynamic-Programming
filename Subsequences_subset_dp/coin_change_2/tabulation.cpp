#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int t=amount;t>=coins[0];t--)
        {
            if(t%coins[0]==0)
                dp[0][t]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=amount;t++)
            {
                int pick=0;
                if(coins[i]<=t)
                    pick=dp[i][t-coins[i]];
                int npick=dp[i-1][t];
                dp[i][t]=pick+npick;
            }
        }
        return dp[n-1][amount];
    }
};

int main() {

    vector<int> arr ={1,2,3};
    int target=4;
    int n =arr.size();
    Solution ob;
    cout<<"The total number of ways is " <<ob.countWaysToMakeChange(arr,n,target);
}