#include <bits/stdc++.h>

using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(num[0]<=tar)
        dp[0][num[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int t=1;t<=tar;t++)
        {
            int pick=0;
            if(num[i]<=t)
                pick=dp[i-1][t-num[i]];
            int npick=dp[i-1][t];
            dp[i][t]=pick+npick;
        }
    }
    return dp[n-1][tar];
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}