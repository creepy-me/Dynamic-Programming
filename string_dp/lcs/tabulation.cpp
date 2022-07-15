#include <bits/stdc++.h>

using namespace std;

int lcs(string t1, string t2) {
        int n1=t1.length();
        int n2=t2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int i1=0;i1<n1;i1++)
        {
            for(int i2=0;i2<n2;i2++)
            {
                if(t1[i1]==t2[i2])
                {
                    dp[i1][i2]=1;
                    if(i2&&i1)
                        dp[i1][i2]+=dp[i1-1][i2-1];
                }
                else
                {
                    int d=0;
                    if(i1)
                        d=max(d,dp[i1-1][i2]);
                    if(i2)
                        d=max(d,dp[i1][i2-1]);
                    dp[i1][i2]=d;
                }
            }
        }
        return dp[n1-1][n2-1];
}

int main() {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}