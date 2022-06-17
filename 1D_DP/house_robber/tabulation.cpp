#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp1(n,-1),dp2(n,-1);
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        dp2[0]=0;
        dp2[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            int pick1 = nums[i]+dp1[i-2];
            int npick1 = dp1[i-1];
            int pick2 = nums[i] + dp2[i-2];
            int npick2 = dp2[i-1];
            dp1[i]= max(pick1,npick1);
            dp2[i]= max(pick2,npick2);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};

main(){
   vector<int> v = {1,2,3,5};
   Solution ob;
   cout << ob.rob(v);
}