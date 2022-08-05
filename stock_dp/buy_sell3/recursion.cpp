#include <bits/stdc++.h>

using namespace std;

int f(int i, bool buy, int cap, vector<int> &p)
{
    if (cap == 0)
        return 0;
    if (i == p.size())
        return 0;
    if (buy)
        return max(-p[i] + f(i + 1, 0, cap, p), f(i + 1, 1, cap, p));
    else
        return max(p[i] + f(i + 1, 1, cap - 1, p), f(i + 1, 0, cap, p));
}
int maxProfit(vector<int> &p)
{
    int n = p.size();
    return f(0, 1, 2, p);
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices);
}