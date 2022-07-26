#include <bits/stdc++.h>

using namespace std;

bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
  if (j < 0)
    return i < 0;
  if (i < 0)
  {
    for (int i1 = 0; i1 <= j; i1++)
    {
      if (p[i1] != '*')
        return false;
    }
    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s[i] == p[j] || p[j] == '?')
    return dp[i][j] = f(i - 1, j - 1, s, p, dp);
  if (p[j] == '*')
    return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
  return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
  int n = s.length(), m = p.length();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n - 1, m - 1, s, p, dp);
}

int main()
{

  string S1 = "ab*cd";
  string S2 = "abdefcd";

  if (isMatch(S2, S1))
    cout << "String S1 and S2 do match";
  else
    cout << "String S1 and S2 do not match";
}