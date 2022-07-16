#include <bits/stdc++.h>

using namespace std;


int lcs(string &n1, string &n2){
	//	Write your code here.
    
    int n=n1.size(),m=n2.size();
        vector<int> dp(m+1,0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {   vector<int> tp(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(n1[i-1]==n2[j-1]){
                    tp[j]=1+dp[j-1];
                    ans=max(ans,tp[j]);
                }
            }
         dp=tp;
        }
        return ans;
    
    return ans;
    
}

int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}