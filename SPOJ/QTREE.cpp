#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
#define lc (i << 1)
#define rc (i << 1 | 1)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e4 + 5, LN = 14;
int N, ed[MN], val[MN], sz[MN], dep[MN], par[MN], hvy[MN], head[MN], pos[MN], cnt;
struct Edge { int v, w, id; };
vector<Edge> g[MN];

struct SegTree {
    int t[2 * MN];
    void init() {
        memset(t, 0, sizeof(t));
    }
    void upd(int i, int v) {
        t[i += N - 1] = v;
        for (i /= 2; i; i /= 2) {
            t[i] = max(t[lc], t[rc]);
        }
    }
    int get(int l, int r) {
        r++;
        int ret = 0;
        for (l += N - 1, r += N - 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ret = max(ret, t[l++]);
            if (r & 1) ret = max(ret, t[--r]);
        }
        return ret;
    }
} t;

void dfs(int u, int d, int p) {
    sz[u] = 1, dep[u] = d, par[u] = p, hvy[u] = 0;
    int mx = 0;
    for (auto [v, w, id] : g[u]) if (v != p) {
        dfs(v, d + 1, u);
        sz[u] += sz[v];
        ed[id] = v, val[v] = w;
        if (mx < sz[v]) mx = sz[v], hvy[u] = v;
    }
}

void hld(int u, int h, int p) {
    pos[u] = ++cnt, head[u] = h;
    t.upd(pos[u], val[u]);
    if (hvy[u]) hld(hvy[u], h, u);
    for (auto [v, w, id] : g[u]) if (v != p && v != hvy[u]) {
        hld(v, v, u);
    }
}

int qry(int u, int v) {
    int ret = 0;
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
        ret = max(ret, t.get(pos[head[v]], pos[v]));
    }
    if (dep[u] > dep[v]) swap(u, v);
    ret = max(ret, t.get(pos[u] + 1, pos[v]));
    return ret;
}

void upd(int i, int w) {
    int v = ed[i];
    val[v] = w;
    t.upd(pos[v], val[v]);
    return;
}

void init(int n) {
    t.init();
    cnt = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
}

void solve() {
    cin >> N;
    init(N);
    for (int i = 1; i < N; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w, i}), g[v].pb({u, w, i});
    }
    dfs(1, 0, 0);
    hld(1, 1, 0);
    string s;
    while (cin >> s && s[0] != 'D') {
        int a, b; cin >> a >> b;
        if (s[0] == 'Q') cout << qry(a, b) << '\n';
        else upd(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
