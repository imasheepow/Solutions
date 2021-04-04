#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5;
int N, ans[MN];
vi g[MN];
set<int> dat[MN];

void dfs(int u, int p) {
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        if (sz(dat[v]) > sz(dat[u])) swap(dat[u], dat[v]);
        dat[u].insert(all(dat[v]));
        dat[v].clear();
    }
    ans[u] = sz(dat[u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1, c; i <= N; i++) cin >> c, dat[i].insert(c);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    return 0;
}
