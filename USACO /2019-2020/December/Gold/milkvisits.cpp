#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, a[MN];
int tin[MN], tout[MN], tt;
vi g[MN], ord;
vector<pii> dat[MN];
int qa[MN], qb[MN], qc[MN];
vector<int> at[MN];
int ans[MN];

void ett(int u, int p) {
    tin[u] = ++tt;
    for (int v : g[u]) if (v != p) ett(v, u);
    tout[u] = tt;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int u, int d, int p) {
    ord.pb(u), dat[a[u]].eb(u, d);
    for (int i : at[u]) if (sz(dat[qc[i]])) {
        auto [v, d] = dat[qc[i]].back();
        if (v == u) ans[i] = 1;
        else {
            int w = ord[d + 1];
            if (!anc(w, qa[i] + qb[i] - u)) ans[i] = 1;
        }
    }
    for (int v : g[u]) if (v != p) dfs(v, d + 1, u);
    ord.pop_back(), dat[a[u]].pop_back();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("milkvisits");
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i = 0; i < M; i++) {
        cin >> qa[i] >> qb[i] >> qc[i];
        at[qa[i]].pb(i);
        at[qb[i]].pb(i);
    }
    ett(1, 0);
    dfs(1, 0, 0);
    for (int i = 0; i < M; i++) cout << ans[i];
    return 0;
}
