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
int N, Q;
int sz[MN], dep[MN], par[MN], hvy[MN], head[MN];
vi g[MN];

void dfs(int u, int d, int p) {
    sz[u] = 1, dep[u] = d, par[u] = p;
    int mx = 0;
    for (int v : g[u]) if (v != p) {
        dfs(v, d + 1, u);
        sz[u] += sz[v];
        if (mx < sz[v]) mx = sz[v], hvy[u] = v;
    }
}

void hld(int u, int h, int p) {
    head[u] = h;
    if (hvy[u]) hld(hvy[u], h, u);
    for (int v : g[u]) if (v != p && v != hvy[u]) {
        hld(v, v, u);
    }
}

int lca(int u, int v) {
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
    }
    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        g[p].pb(i);
    }
    dfs(1, 0, 0);
    hld(1, 1, 0);
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
