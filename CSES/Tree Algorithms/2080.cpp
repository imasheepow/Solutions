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
int N, K, sz[MN], cnt[MN], mxDep;
ll ans;
vi g[MN];
bool done[MN];

int getSz(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) if (v != p && !done[v])
        sz[u] += getSz(v, u);
    return sz[u];
}

int getCentroid(int u, int p, int s) {
    for (int v : g[u]) if (v != p && !done[v] && sz[v] > s / 2)
        return getCentroid(v, u, s);
    return u;
}

void dfs(int u, int p, bool tp, int d) {
    if (d > K) return;
    if (tp) cnt[d]++;
    else mxDep = max(mxDep, d), ans += cnt[K - d];
    for (int v : g[u]) if (v != p && !done[v])
        dfs(v, u, tp, d + 1);
}

void go(int u) {
    int c = getCentroid(u, 0, getSz(u, 0));
    mxDep = 0;
    for (int v : g[c]) if (!done[v]) {
        dfs(v, c, false, 1);
        dfs(v, c, true, 1);
    }
    fill(cnt + 1, cnt + 1 + mxDep, 0);
    done[c] = true;
    for (int v : g[c])
        if (!done[v]) go(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    cnt[0] = 1;
    go(1);
    cout << ans << '\n';
    return 0;
}
