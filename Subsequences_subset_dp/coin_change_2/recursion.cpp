#include <bits/stdc++.h>

using namespace std;

class Solution {
    int f(int i,int t,vector<int>& coins)
    {
        if(t==0)
            return 1;
        if(i==0)
            return t%coins[i]==0;
        int pick=0;
        if(coins[i]<=t)
            pick=f(i,t-coins[i],coins);
        int npick=f(i-1,t,coins);
        return pick+npick;
    }
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        int n=coins.size();
        return f(n-1,amount,coins);
    }
};

int main() {

    vector<int> arr ={1,2,3};
    int target=4;
    int n =arr.size();
    Solution ob;
    cout<<"The total number of ways is " <<ob.countWaysToMakeChange(arr,n,target);
}