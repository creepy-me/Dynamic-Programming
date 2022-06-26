#include <bits/stdc++.h>

using namespace std;

int sub(int i,vector<int>& a,int t,vector<vector<int>> &dp)
{
    if(t==0)
        return dp[i][0]=1;
    if(i==0)
        return dp[0][t]=(a[i]==t);
    if(t==0)
        return 1;
    if(dp[i][t]!=-1)
        return dp[i][t];
    int pick=0;
    if(a[i]<=t)
        pick=sub(i-1,a,t-a[i],dp);
    int npick=sub(i-1,a,t,dp);
    return dp[i][t]=pick+npick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return sub(n-1,num,tar,dp);
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}