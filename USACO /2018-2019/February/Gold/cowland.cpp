#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, LN = 17;
int N, Q, a[MN], dep[MN], up[MN][LN], tin[MN], tout[MN], tt;
vi g[MN];

void et(int u, int p = -1) {
    tin[u] = ++tt;
    up[u][0] = p;
    for (int j = 1; j < LN; j++)
        if (~up[u][j - 1]) up[u][j] = up[up[u][j - 1]][j - 1];
    for (int v : g[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        et(v, u);
    }
    tout[u] = tt;
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

int b[MN];
void upd(int i, int v) {
    for (; i < MN; i += i & -i) b[i] ^= v;
}
int get(int i) {
    int r = 0;
    for (; i; i -= i & -i) r ^= b[i];
    return r;
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("cowland");
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(up, -1, sizeof(up));
    et(1);
    for (int i = 1; i <= N; i++) {
        upd(tin[i], a[i]);
        upd(tout[i] + 1, a[i]);
    }
    for (int i = 0; i < Q; i++) {
        int tp, x, y; cin >> tp >> x >> y;
        if (tp == 1) {
            upd(tin[x], a[x]);
            upd(tout[x] + 1, a[x]);
            upd(tin[x], y);
            upd(tout[x] + 1, y);
            a[x] = y;
        } else {
            int anc = lca(x, y);
            int val = get(tin[x]) ^ get(tin[y]);
            if (~anc) val ^= a[anc];
            cout << val << '\n';
        }
    }
    return 0;
}
