#include <bits/stdc++.h>

using namespace std;

int f(int i1, int i2, string &t1, string &t2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (t1[i1] == t2[i2])
        return dp[i1][i2] = 1 + f(i1 - 1, i2 - 1, t1, t2, dp);
    return dp[i1][i2] = max(f(i1, i2 - 1, t1, t2, dp), f(i1 - 1, i2, t1, t2, dp));
}
int lcs(string t1, string t2)
{
    int n1 = t1.length();
    int n2 = t2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(n1 - 1, n2 - 1, t1, t2, dp);
}

int main()
{

    string s1 = "acd";
    string s2 = "ced";

    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2);
}