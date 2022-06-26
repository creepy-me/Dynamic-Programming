#include <bits/stdc++.h>

using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<int> dp(tar+1,0);
    dp[0]=1;
    if(num[0]<=tar)
        dp[num[0]]=1;
    for(int i=1;i<n;i++)
    {
        vector<int> tp(tar+1,1);
        for(int t=1;t<=tar;t++)
        {
            int pick=0;
            if(num[i]<=t)
                pick=dp[t-num[i]];
            int npick=dp[t];
            tp[t]=pick+npick;
        }
        dp=tp;
    }
    return dp[tar];
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}