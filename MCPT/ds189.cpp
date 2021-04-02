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
const int MN = 1e5 + 5;
int N, Q, a[MN];
int sz[MN], dep[MN], par[MN], hvy[MN], head[MN];
int tin[MN], tout[MN], tt;
vi g[MN];

struct SegTree {
    int a[MN], t[MN * 4], lz[MN * 4];
    int build(int i = 1, int l = 1, int r = N) {
        lz[i] = 0;
        if (l == r) return t[i] = a[l];
        int m = (l + r) / 2;
        return t[i] = max(build(lc, l, m), build(rc, m + 1, r));
    }
    void push(int i, int l, int r) {
        if (lz[i]) {
            t[i] += lz[i];
            if (l != r) {
                lz[lc] += lz[i];
                lz[rc] += lz[i];
            }
            lz[i] = 0;
        }
    }
    int upd(int ql, int qr, int v, int i = 1, int l = 1, int r = N) {
        push(i, l, r);
        if (l > qr || r < ql) return t[i];
        if (l >= ql && r <= qr) {
            lz[i] += v, push(i, l, r);
            return t[i];
        }
        int m = (l + r) / 2;
        return t[i] = max(upd(ql, qr, v, lc, l, m), upd(ql, qr, v, rc, m + 1, r));
    }
    int get(int ql, int qr, int i = 1, int l = 1, int r = N) {
        push(i, l, r);
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return t[i];
        int m = (l + r) / 2;
        return max(get(ql, qr, lc, l, m), get(ql, qr, rc, m + 1, r));
    }
} seg;

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
    tin[u] = ++tt;
    seg.a[tin[u]]= a[u];
    head[u] = h;
    if (hvy[u]) hld(hvy[u], h, u);
    for (int v : g[u]) if (v != p && v != hvy[u]) {
        hld(v, v, u);
    }
    tout[u] = tt;
}

void pathUpd(int u, int v, int x) {
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
        seg.upd(tin[head[v]], tin[v], x);
    }
    if (dep[u] > dep[v]) swap(u, v);
    seg.upd(tin[u], tin[v], x);
}

int pathQry(int u, int v) {
    int ret = 0;
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (dep[head[u]] > dep[head[v]]) swap(u, v);
        ret = max(ret, seg.get(tin[head[v]], tin[v]));
    }
    if (dep[u] > dep[v]) swap(u, v);
    ret = max(ret, seg.get(tin[u], tin[v]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) {
        int p; cin >> p;
        if (p) g[p].pb(i);
    }
    dfs(1, 0, 0);
    hld(1, 1, 0);
    seg.build();
    for (int i = 0; i < Q; i++) {
        int op, u, v, x; cin >> op >> u;
        if (op == 1) {
            cin >> x;
            seg.upd(tin[u], tout[u], x);
        } else if (op == 2) {
            cin >> v >> x;
            pathUpd(u, v, x);
        } else if (op == 3) {
            cout << seg.get(tin[u], tout[u]) << '\n';
        } else {
            cin >> v;
            cout << pathQry(u, v) << '\n';
        }
    }
    return 0;
}
