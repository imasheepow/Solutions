#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2005;
int n, s[MN]; ll dp[MN][MN];

ll go(int l, int r) {
   if (~dp[l][r]) return dp[l][r];
   if (l == r) return 0;
   ll &ret = dp[l][r];
   return ret = s[r] - s[l] + min(go(l + 1, r), go(l, r - 1));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= n; j++) dp[i][j] = -1;
    }
    sort(s + 1, s + 1 + n);
    cout << go(1, n) << '\n';
    return 0;
}
