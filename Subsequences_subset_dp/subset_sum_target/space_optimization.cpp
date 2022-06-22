// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool> dp(sum+1,false);
        //for(int i=0;i<n;i++)
            dp[0]=true;
        if(arr[0]<=sum)
            dp[arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            vector<bool> t(sum+1,false);
            for(int j=1;j<=sum;j++)
            {
                bool pick=false;
                if(arr[i]<=j)
                    pick = dp[j-arr[i]];
                bool npick = dp[j];
                t[j]=(pick||npick);
            }
            dp=t;
        }
        return dp[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends