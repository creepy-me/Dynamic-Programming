#include <bits/stdc++.h>

using namespace std;

int sub(int i,vector<int>& a,int t)
{
    if(t==0)
        return 1;
    if(i==0)
        return a[i]==t;
    int pick=0;
    if(a[i]<=t)
        pick=sub(i-1,a,t-a[i]);
    int npick=sub(i-1,a,t);
    return pick+npick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    return sub(n-1,num,tar);
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}