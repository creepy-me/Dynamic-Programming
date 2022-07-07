#include <bits/stdc++.h>

using namespace std;

class Solution {
    int f(int i,int t,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(t==0)
            return 1;
        if(i==0)
            return t%coins[i]==0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        int pick=0;
        if(coins[i]<=t)
            pick=f(i,t-coins[i],coins,dp);
        int npick=f(i-1,t,coins,dp);
        return dp[i][t]=pick+npick;
    }
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};

int main() {

    vector<int> arr ={1,2,3};
    int target=4;
    int n =arr.size();
    Solution ob;
    cout<<"The total number of ways is " <<ob.countWaysToMakeChange(arr,n,target);
}