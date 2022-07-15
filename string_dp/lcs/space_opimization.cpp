#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length();
        int n2=t2.length();
        vector<int> dp(n2,0);
        for(int i1=0;i1<n1;i1++)
        {
            vector<int> tp(n2,0);
            for(int i2=0;i2<n2;i2++)
            {
                if(t1[i1]==t2[i2])
                {
                    tp[i2]=1;
                    if(i2&&i1)
                        tp[i2]+=dp[i2-1];
                }
                else
                {
                    int d=0;
                    if(i1)
                        d=max(d,dp[i2]);
                    if(i2)
                        d=max(d,tp[i2-1]);
                    tp[i2]=d;
                }
            }
            dp=tp;
        }
        return dp[n2-1];
}

int main() {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}