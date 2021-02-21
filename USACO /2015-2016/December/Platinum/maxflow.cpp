#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e4 + 5, LN = 16;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, K;
vi g[MN];
int dep[MN], up[MN][LN];
void dfs(int u, int p) {
    for (int j = 1; j < LN; j++) {
        if (~up[u][j - 1]) up[u][j] = up[up[u][j - 1]][j - 1];
        else break;
    }
    for (int v : g[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LN - 1; i >= 0; i--)
        if (~up[u][i] && dep[up[u][i]] >= dep[v])
            u = up[u][i];
    if (u == v) return u;
    for (int i = LN - 1; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

int ans[MN], ps[MN];
void go(int u, int p) {
    for (int v : g[u]) if (v != p) {
        go(v, u);
        ps[u] += ps[v];
    }
    ans[u] += ps[u];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("maxflow");
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    memset(up, -1, sizeof(up));
    dfs(1, -1);
    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        int anc = lca(u, v);
        ps[u]++, ps[v]++, ps[anc] -= 2;
        ans[anc]++;
    }
    go(1, -1);
    cout << *max_element(ans + 1, ans + 1 + N) << '\n';
    return 0;
}
