#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int n=coins.size();
        vector<int> dp(amount+1,0);
            dp[0]=1;
        for(int t=amount;t>=coins[0];t--)
        {
            if(t%coins[0]==0)
                dp[t]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=amount;t++)
            {
                int pick=0;
                if(coins[i]<=t)
                    pick=dp[t-coins[i]];
                int npick=dp[t];
                dp[t]=pick+npick;
            }
        }
        return dp[amount];
    }
};

int main() {

    vector<int> arr ={1,2,3};
    int target=4;
    int n =arr.size();
    Solution ob;
    cout<<"The total number of ways is " <<ob.countWaysToMakeChange(arr,n,target);
}