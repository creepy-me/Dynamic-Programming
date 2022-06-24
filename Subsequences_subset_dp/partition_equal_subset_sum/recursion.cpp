// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    bool check(int i,vector<int>& a,int t)
    {
        if(t==0)
            return true;
        if(i==0)
            return a[i]==t;
        bool pick = check(i-1,a,t-a[i]);
        bool npick = check(i-1,a,t);
        return pick||npick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        return check(nums.size()-1,nums,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N,0);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.canPartition(arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends