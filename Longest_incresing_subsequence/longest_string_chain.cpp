//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    bool comp(string &a,string &b)
    {
        int n=a.length(),m=b.length();
        if(m-n!=1)
            return false;
        int i=0,j=0;
        while(j<m)
        {
            if(a[i]==b[j])
            {i++;
            j++;}
            else
                j++;
        }
        if(i==n&&j==m)
            return true;
        return false;
    }
    static bool cmp(string& a,string& b)
    {
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size(),ans=0,ind=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(comp(words[j],words[i])&&dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>ans)
                ans=dp[i];
        }
        return ans;
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
        vector<string> nums(n);
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>nums[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestStrChain(nums) << endl;
    }
}

// } Driver Code Ends