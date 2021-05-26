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

int n, c[MN];
vi g[MN];
map<int, int> mp[MN];
int id[MN], mx[MN];
ll sum[MN], ans[MN];

void merge(int u, int v) {
    if (sz(mp[id[u]]) < sz(mp[id[v]])) swap(id[u], id[v]);
    for (auto [x, y] : mp[id[v]]) {
        mp[id[u]][x] += y;
        if (mp[id[u]][x] > mx[id[u]]) {
            mx[id[u]] = mp[id[u]][x];
            sum[id[u]] = 0;
        }
        if (mp[id[u]][x] == mx[id[u]]) {
            sum[id[u]] += x;
        }
    }
}

void dfs(int u, int p) {
    id[u] = u;
    mp[u][c[u]] = 1;
    mx[u] = 1;
    sum[u] = c[u];
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        merge(u, v);
    }
    ans[u] = sum[id[u]];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
