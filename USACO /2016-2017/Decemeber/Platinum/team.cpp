#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e3 + 5, MOD = 1e9 + 9;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, K, a[MN], b[MN];
ll dp[MN][MN][15];

ll go(int i, int j, int k) {
    if (k && (!i || !j)) return 0;
    if (!k) return 1;
    if (~dp[i][j][k]) return dp[i][j][k];
    ll &ret = dp[i][j][k] = 0;
    if (a[i] > b[j]) ret = (ret + go(i - 1, j - 1, k - 1)) % MOD;
    ret = (ret + go(i - 1, j, k)) % MOD;
    ret = (ret + go(i, j - 1, k)) % MOD;
    ret = (ret - go(i - 1, j - 1, k) + MOD) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("team");
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= M; i++) cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << go(N, M, K) << '\n';
    return 0;
}
