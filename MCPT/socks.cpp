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
const int MN = 2e5 + 5;
int N, Q, a[MN];
int sz[MN], dep[MN], par[MN], hvy[MN], head[MN];
int tin[MN], tt;
vi g[MN];
struct Node {
    ll sum, pre, suf, mx;
    Node () {}
    Node (ll val) : sum(val), pre(val), suf(val), mx(val) {}
    Node (Node l, Node r) {
        mx = max(max(l.mx, r.mx), l.suf + r.pre);
        pre = max(l.pre, l.sum + r.pre);
        suf = max(r.suf, r.sum + l.suf);
        sum = l.sum + r.sum;
    }
};
template <typename T>
struct SegTree {
    T t[MN * 4];
    T merge(T x, T y) {
        return Node(x, y);
    }
    void upd(int x, int v, int i = 1, int l = 1, int r = N) {
        if (l == r) { t[i] = Node(v); return; }
        int m = (l + r) / 2;
        if (x <= m) upd(x, v, lc, l, m);
        else upd(x, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    T get(int ql, int qr, int i = 1, int l = 1, int r = N) {
        if (l >= ql && r <= qr) return t[i];
        int m = (l + r) / 2;
        if (qr <= m) return get(ql, qr, lc, l, m);
        if (ql > m) return get(ql, qr, rc, m + 1, r);
        return merge(get(ql, qr, lc, l, m), get(ql, qr, rc, m + 1, r));
    }
};
SegTree<Node> seg;
void dfs(int u, int d, int p) {
    sz[u] = 1, dep[u] = d, par[u] = p;
    int mx = 0;
    for (int v : g[u]) if (v != p) {
        dfs(v, d + 1, u);
        sz[u] += sz[v];
        if (sz[v] > mx) mx = sz[v], hvy[u] = v;
    }
}
void hld(int u, int h, int p) {
    tin[u] = ++tt, head[u] = h;
    seg.upd(tin[u], a[u]);
    if (hvy[u]) hld(hvy[u], h, u);
    for (int v : g[u]) if (v != p && v != hvy[u]) {
        hld(v, v, u);
    }
}
ll qry(int u, int v) {
    Node up = Node(-1e18), down = Node(-1e18); bool cur = false;
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v), cur = !cur;
        if (cur) down = Node(seg.get(tin[head[v]], tin[v]), down);
        else up = Node(seg.get(tin[head[v]], tin[v]), up);
    }
    if (dep[u] > dep[v]) swap(u, v), cur = !cur;
    if (cur) down = Node(seg.get(tin[u], tin[v]), down);
    else up = Node(seg.get(tin[u], tin[v]), up);
    swap(up.pre, up.suf);
    return Node(up, down).mx;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0, 0), hld(1, 1, 0);
    for (int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        cout << qry(x, y) << '\n';
    }
    return 0;
}