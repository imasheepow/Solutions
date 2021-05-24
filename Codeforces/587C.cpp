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

int n, m, q;
vi g[MN];
int up[MN][LN], dep[MN];
vi s[MN][LN];

void dfs(int u, int p) {
    for (int v : g[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        dfs(v, u);
    }
}

void merge(vi &a, vi b, int k) {
    vi c;
    merge(all(a), all(b), back_inserter(c));
    c.resize(min(sz(c), k));
    a.swap(c);
}

vi get(int u, int v, int k) {
    vi ret;
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LN - 1; i >= 0; i--) {
        if (~up[u][i] && dep[up[u][i]] >= dep[v]) {
            merge(ret, s[u][i], k);
            u = up[u][i];
        }
    }
    if (u == v) {
        merge(ret, s[u][0], k);
        return ret;
    }
    for (int i = LN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            merge(ret, s[u][i], k);
            merge(ret, s[v][i], k);
            u = up[u][i], v = up[v][i];
        }
    }
    merge(ret, s[u][0], k);
    merge(ret, s[v][1], k);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i = 1; i <= m; i++) {
        int c; cin >> c;
        s[c][0].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(s[i][0]));
        s[i][0].resize(min(sz(s[i][0]), 10));
    }
    memset(up, -1, sizeof(up));
    dfs(1, -1);
    for (int j = 1; j < LN; j++) {
        for (int i = 1; i <= n; i++) {
            if (~up[i][j - 1]) {
                up[i][j] = up[up[i][j - 1]][j - 1];
                merge(all(s[i][j - 1]), all(s[up[i][j - 1]][j - 1]), back_inserter(s[i][j]));
                s[i][j].resize(min(sz(s[i][j]), 10));
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v, k; cin >> u >> v >> k;
        vi ret = get(u, v, k);
        cout << sz(ret) << ' ';
        for (int x : ret) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
