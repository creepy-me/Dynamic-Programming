#include <bits/stdc++.h>

using namespace std;

int f(int i, bool buy, int k, vector<int> &p)
{
    if (k == 0)
        return 0;
    if (i >= p.size())
        return 0;
    if (buy)
        return max(-p[i] + f(i + 1, 0, k, p), f(i + 1, 1, k, p));
    else
        return max(p[i] + f(i + 1, 1, k - 1, p), f(i + 1, 0, k, p));
}
int maxProfit(int k, vector<int> &p)
{
    int n = p.size();
    return f(0, 1, k, p);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2, n = prices.size();
    cout << "The maximum profit that can be generated is " << maxProfit(k,prices);
}