#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, MOD = 1e9 + 7;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, K, clr[MN];
vi g[MN];
ll dp[MN][4];

void dfs(int u, int p) {
    if (clr[u]) {
        dp[u][clr[u]] = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            ll add = 0;
            for (int c = 1; c <= 3; c++) {
                if (c != clr[u]) {
                    add = (add + dp[v][c]) % MOD;
                }
            }
            dp[u][clr[u]] = (dp[u][clr[u]] * add) % MOD;
        }
    } else {
        dp[u][1] = dp[u][2] = dp[u][3] = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (int a = 1; a <= 3; a++) {
                ll add = 0;
                for (int b = 1; b <= 3; b++) {
                    if (a != b) {
                        add = (add + dp[v][b]) % MOD;
                    }
                }
                dp[u][a] = (dp[u][a] * add) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("barnpainting");
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        clr[x] = y;
    }
    dfs(1, -1);
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD << '\n';
    return 0;
}
