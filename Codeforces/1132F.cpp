#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 505;

int n, dp[MN][MN];
char s[MN];

int go(int l, int r) {
    int &ret = dp[l][r];
    if (~ret) return ret;
    if (l > r) return ret = 0;
    if (l == r) return ret = 1;
    ret = 1 + go(l + 1, r); // delete first separately
    for (int i = l + 1; i <= r; i++)
        if (s[l] == s[i]) // delete with another string
            ret = min(ret, go(l + 1, i - 1) + go(i, r));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> (s + 1);
    memset(dp, -1, sizeof(dp));
    cout << go(1, n) << '\n';
    return 0;
}
