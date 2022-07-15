#include <bits/stdc++.h>

using namespace std;

int f(int i1,int i2,string t1,string t2)
    {
        if(i1<0 || i2<0)
            return 0;
        if(t1[i1]==t2[i2])
            return 1+f(i1-1,i2-1,t1,t2);
        return max(f(i1,i2-1,t1,t2),f(i1-1,i2,t1,t2));
    }
int lcs(string t1, string t2) {
    int n1=t1.length();
    int n2=t2.length();
    return f(n1-1,n2-1,t1,t2);
}

int main() {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}