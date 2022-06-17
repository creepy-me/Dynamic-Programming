#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];

        int cur1,p1,pp1,cur2,p2,pp2;
        p1=nums[0];
        pp1=max(nums[0],nums[1]);
        p2=0;
        pp2=nums[1];
        for(int i=2;i<n;i++)
        {
            int pick2 = nums[i] + p2;
            int npick2 = pp2;
            cur2= max(pick2,npick2);
            p2=pp2;
            pp2=cur2;

            if(i<n-1){
            int pick1 = nums[i]+p1;
            int npick1 = pp1;
            cur1= max(pick1,npick1);
            p1=pp1;
            pp1=cur1;            
            }
        }
        return max(pp1,pp2);
    }
};

main(){
   vector<int> v = {1,2,3,5};
   Solution ob;
   cout << ob.rob(v);
}