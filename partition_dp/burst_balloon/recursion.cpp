// { Driver Code Starts
//Initial Template for C++#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int f(int i,int j,vector<int>& nums)
    {
        if(i>j)
            return 0;
        int cur,ans=0;
        for(int k=i;k<=j;k++)
        {
            cur=nums[i-1]*nums[k]*nums[j+1] + f(i,k-1,nums) + f(k+1,j,nums);
            ans=max(ans,cur);
        }
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size()-2;
        return f(1,n,nums);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.maxCoins(arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends