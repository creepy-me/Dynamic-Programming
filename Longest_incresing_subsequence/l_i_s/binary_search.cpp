//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
                temp.push_back(nums[i]);
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        vector<int> nums(n);
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>nums[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.lengthOfLIS(nums) << endl;
    }
}

// } Driver Code Ends