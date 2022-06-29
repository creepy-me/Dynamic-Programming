#include <bits/stdc++.h>

using namespace std;

int mod =(int)1e9+7;

int count(int i,int t,vector<int> &a)
{
    if(i==0)
    {
        if(t==0 && a[i]==0)
            return 2;
        if(t==0 || t==a[0])
            return 1;
        return 0;
    }
    int pick=0;
    if(a[i]<=t)
        pick=count(i-1,t-a[i],a)%mod;
    int npick=count(i-1,t,a)%mod;
    return (pick+npick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tot=accumulate(arr.begin(),arr.end(),0);
    tot-=d;
    if(tot<0 || tot&1)
        return 0;
    return count(n-1,tot/2,arr)%mod;
}

int main() {

  vector<int> arr = {5,2,6,4};
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(4,d,arr);
}