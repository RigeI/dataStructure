#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.first < p2.first) {
        return true;
    }
    if (p1.first > p2.first) {
        return false;
    }
    if (p1.second > p2.second) {
        return true;
    }
    return false;
}

int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);
    int dp[100001];
    memset(dp, 0, sizeof(int) * envelopes.size());
    int len = 1;
    dp[0] = envelopes[0].second;
    for (int i = 1; i < (int)envelopes.size(); ++i) {
        int pos = lower_bound(dp, dp + len, envelopes[i].second) - dp;
        dp[pos] = envelopes[i].second;
        len = max(len, pos + 1);
    }
    return len;
}

int main()
{
    vector<pair<int, int>> v;
    pair<int, int> p;
    while (cin >> p.first >> p.second) {
        v.push_back(p);
    }
    cout << maxEnvelopes(v) << endl;
}
