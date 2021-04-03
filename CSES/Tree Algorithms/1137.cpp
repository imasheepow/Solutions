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
int N, Q, a[MN]; ll b[MN];
int tin[MN], tout[MN], tt;
vi g[MN];

void upd(int i, int v) {
    for (; i < MN; i += i & -i) b[i] += v;
}

ll get(int i) {
    ll ret = 0;
    for (; i; i -= i & -i) ret += b[i];
    return ret;
}

void dfs(int u, int p) {
    tin[u] = ++tt;
    for (int v : g[u]) if (v != p) dfs(v, u);
    tout[u] = tt;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++) upd(tin[i], a[i]);
    for (int i = 0; i < Q; i++) {
        int op, u, x; cin >> op >> u;
        if (op == 1) {
            cin >> x;
            upd(tin[u], -a[u] + x);
            a[u] = x;
        } else {
            cout << get(tout[u]) - get(tin[u] - 1) << '\n';
        }
    }
    return 0;
}
