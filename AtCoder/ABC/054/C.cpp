#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 10;
int N, M;
vi g[MN];
int dp[8][1 << 8];

int go(int u, int msk) {
    if (~dp[u][msk]) return dp[u][msk];
    if (msk == (1 << N) - 1) return dp[u][msk] = 1;
    int &ret = dp[u][msk] = 0;
    for (int v : g[u]) {
        if (!(msk & (1 << v))) {
            int nxt = msk | (1 << v);
            ret = (ret + go(v, nxt));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v), g[v].pb(u);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << '\n';
    return 0;
}
