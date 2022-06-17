#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(vector<vector<int>>& t,int i,int j)
    {
        if(i==t.size()-1)
            return t[i][j];
        int d=f(t,i+1,j);
        int dg=f(t,i+1,j+1);
        return t[i][j] + min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        return f(t,0,0);
    }
};

int main()
{
	vector<vector<int> > A{ { 2 },
				{ 3, 9 },
				{ 1, 6, 7 } };
    Solution ob;
	cout << ob.minimumTotal(A);
	return 0;
}
