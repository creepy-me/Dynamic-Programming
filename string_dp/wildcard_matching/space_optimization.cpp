#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p)
{
  int n = s.length(), m = p.length();
  vector<bool> dp(m + 1, false), tp(m + 1, false);
  dp[0] = true;
  for (int j = 1; j <= m; j++)
  {
    if (p[j - 1] == '*')
      dp[j] = true;
    else
      break;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        tp[j] = dp[j - 1];
      else if (p[j - 1] == '*')
        tp[j] = dp[j] || tp[j - 1];
      else
        tp[j] = false;
    }
    dp = tp;
  }
  return dp[m];
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