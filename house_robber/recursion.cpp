#include<bits/stdc++.h>
using namespace std;

class Solution {
    int robber(vector<int> &nums,int i,int k)
    {
        if(i==0 && k==0)
            return 0;
        if(i==0)
            return nums[0];
        if(i<0)
            return 0;
        int pick = nums[i];
        int npick=0;
        npick += robber(nums,i-1,k);
        pick += robber(nums,i-2,k);
        return max(pick,npick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(robber(nums,n-1,0),robber(nums,n-2,n-1));
    }
};

main(){
   vector<int> v = {1,2,3,5};
   Solution ob;
   cout << ob.rob(v);
}