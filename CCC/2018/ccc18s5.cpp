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
int N, M, P, Q;
struct Edge {
    int tp, u, v, w;
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};
vector<Edge> ed;
int comps[MN];
int par[2][MN];
int find(int t, int u) {
    return u == par[t][u] ? u : par[t][u] = find(t, par[t][u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> P >> Q;
    comps[0] = M, comps[1] = N;
    ll ans = 0;
    for (int i = 0; i < P; i++) {
        int u, v, w; cin >> u >> v >> w;
        ed.pb({0, u, v, w});
        ans += w * 1LL * N;
    }
    for (int i = 0; i < Q; i++) {
        int u, v, w; cin >> u >> v >> w;
        ed.pb({1, u, v, w});
        ans += w * 1LL * M;
    }
    sort(all(ed));
    for (int i = 1; i <= M; i++) par[0][i] = i;
    for (int i = 1; i <= N; i++) par[1][i] = i;
    for (auto [t, u, v, w] : ed) {
        u = find(t, u), v = find(t, v);
        if (u == v) continue;
        par[t][v] = u, comps[t]--;
        ans -= w * 1LL * comps[!t];
    }
    cout << ans << '\n';
    return 0;
}
