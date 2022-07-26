#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p)
{
  int n = s.length(), m = p.length();
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;
  for (int j = 1; j <= m; j++)
  {
    if (p[j - 1] == '*')
      dp[0][j] = true;
    else
      break;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (p[j - 1] == '*')
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      else
        dp[i][j] = false;
    }
  }
  return dp[n][m];
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