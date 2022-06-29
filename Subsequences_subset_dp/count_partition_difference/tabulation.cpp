#include <bits/stdc++.h>

using namespace std;

int mod =(int)1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tot=accumulate(arr.begin(),arr.end(),0);
    tot-=d;
    if(tot<0 || tot&1)
        return 0;
    tot/=2;
    vector<vector<int>> dp(n,vector<int>(tot+1,0));
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=tot)
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int t=0;t<=tot;t++)
        {
            int pick=0;
            if(arr[i]<=t)
                pick=dp[i-1][t-arr[i]]%mod;
            int npick=dp[i-1][t]%mod;
            dp[i][t]=(pick+npick)%mod;
        }
    }
    return dp[n-1][tot];
}

int main() {

  vector<int> arr = {5,2,6,4};
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(4,d,arr);
}