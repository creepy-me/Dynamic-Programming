#include <bits/stdc++.h>

using namespace std;

int minCost(int i,vector<int> &h,int k,vector<int> &dp)
{
    if(i==0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int cost=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if((i-j)>=0)
        {
            int c=minCost(i-j,h,k,dp) + abs(h[i]-h[i-j]);
            cost=min(cost,c);
        }
    }
    return dp[i]=cost;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> h;
    for(int i=0;i<n;i++)
    {
        int ht;
        cin>>ht;
        h.push_back(ht);
    }
    vector<int> dp(n,-1);
    cout<<minCost(n-1,h,k,dp);
}