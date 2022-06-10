#include <bits/stdc++.h>

using namespace std;

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
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int cost=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            {
                int c=dp[i-j] + abs(h[i]-h[i-j]);
                cost=min(cost,c);
            }
        }
        dp[i]=cost;
    }
    cout<<dp[n-1];
}