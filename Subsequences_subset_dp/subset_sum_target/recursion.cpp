// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    bool check(int i,int sum,vector<int> arr)
    {
        if(sum==0)
            return true;
        if(sum<0)
            return false;
        if(i==0)
        {
            return arr[0]==sum;
        }
        bool pick = check(i-1,sum-arr[i],arr);
        bool npick= check(i-1,sum,arr);
        return (pick||npick);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return check(arr.size()-1,sum,arr);
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