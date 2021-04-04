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
int N, sz[MN];
vi g[MN];

int getSz(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) if (v != p)
        sz[u] += getSz(v, u);
    return sz[u];
}

int getCentroid(int u, int p, int s) {
    for (int v : g[u]) if (v != p && sz[v] > s / 2)
        return getCentroid(v, u, s);
    return u;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    getSz(1, 0);
    cout << getCentroid(1, 0, sz[1]) << '\n';
    return 0;
}
