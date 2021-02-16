#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5, LN = 18;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// count pairs of cycles that overlap by at least 1 edge
int N, M;
vi g[MN];
int dep[MN], up[MN][LN];
int a[MN], b[MN], c[MN];
ll ps[MN];
map<pii, ll> mp;

void get(int u, int p = -1) {
    if (~p) g[u].erase(find(all(g[u]), p));
    for (int i = 1; i < LN; i++)
        if (~up[u][i - 1]) up[u][i] = up[up[u][i - 1]][i - 1];
        else break;
    for (int v : g[u]) {
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        get(v, u);
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

int top(int anc, int u) {
    if (anc == u) return -1;
    for (int i = LN - 1; i >= 0; i--)
        if (~up[u][i] && dep[up[u][i]] > dep[anc])
            u = up[u][i];
    return u;
}

void dfs(int u) {
    for (int v : g[u]) {
        ps[v] += ps[u];
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("exercise");
    cin >> N >> M;
    int Q = M - (N - 1);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    memset(up, -1, sizeof(up));
    get(1);
    ll ans = 0;
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v;
        a[i] = u, b[i] = v;
        int anc = lca(u, v);
        c[i] = anc;
        int tu = top(anc, u);
        if (~tu) {
            ans -= ps[tu] + 1;
            ps[tu]++;
        }
        int tv = top(anc, v);
        if (~tv) {
            ans -= ps[tv] + 1;
            ps[tv]++;
        }
        if (~tu && ~tv) {
            if (tu > tv) swap(tu, tv);
            ans -= mp[{tu, tv}];
            mp[{tu, tv}]++;
        }
    }
    dfs(1);
    for (int i = 0; i < Q; i++) {
        ans += ps[a[i]] + ps[b[i]] - 2 * ps[c[i]];
    }
    cout << ans << '\n';
    return 0;
}
