#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 205, MM = 5e4 + 5;
int N, M, a[MM], b[MM]; ll c[MM], d[MM];
vi g[MN], rg[MN];
ll dis[2][MN], rdis[2][MN];
int from[2][MN];
bool vis[MN];
bool used[MM];

void dijk(int t, int st) {
    for (int i = 0; i <= N; i++) dis[t][i] = 1e18, vis[i] = 0;
    dis[t][st] = 0;
    for (int i = 0; i < N; i++) {
        int u = 0;
        for (int v = 1; v <= N; v++) {
            if (!vis[v] && dis[t][v] < dis[t][u]) {
                u = v;
            }
        }
        if (!u) break;
        vis[u] = 1;
        for (int e : g[u]) {
            if (u != a[e]) continue;
            int v = b[e], w = c[e];
            if (dis[t][v] > dis[t][u] + w) {
                dis[t][v] = dis[t][u] + w;
                from[t][v] = e;
            }
        }
    }
}

void rdijk(int t, int st) {
    for (int i = 0; i <= N; i++) rdis[t][i] = 1e18, vis[i] = 0;
    rdis[t][st] = 0;
    for (int i = 0; i < N; i++) {
        int u = 0;
        for (int v = 1; v <= N; v++) {
            if (!vis[v] && rdis[t][v] < rdis[t][u]) {
                u = v;
            }
        }
        if (!u) break;
        vis[u] = 1;
        for (int e : rg[u]) {
            int v = a[e], w = c[e];
            if (rdis[t][v] > rdis[t][u] + w) {
                rdis[t][v] = rdis[t][u] + w;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        g[a[i]].pb(i), rg[b[i]].pb(i);
    }
    dijk(0, 1), dijk(1, N);
    rdijk(0, N), rdijk(1, 1);
    ll ans = dis[0][N] + dis[1][1];
    int cur = N;
    while (from[0][cur] && cur != 1) {
        used[from[0][cur]] = 1;
        cur = a[from[0][cur]];
    }
    cur = 1;
    while (from[1][cur] && cur != N) {
        used[from[1][cur]] = 1;
        cur = a[from[1][cur]];
    }
    for (int i = 1; i <= M; i++) {
        int u = a[i], v = b[i], w = c[i];
        if (!used[i]) {
            ll mn = dis[0][v] + w + rdis[0][u] + dis[1][v] + w + rdis[1][u];
            mn = min(mn, dis[1][1] + dis[0][v] + w + rdis[0][u]);
            mn = min(mn, dis[0][N] + dis[1][v] + w + rdis[1][u]);
            ans = min(ans, mn + d[i]);
        }
    }
    for (int i = 1; i <= M; i++) {
        int u = a[i], v = b[i], w = c[i];
        if (used[i]) {
            swap(a[i], b[i]);
            g[v].pb(i);
            dijk(0, 1), dijk(1, N);
            g[v].pop_back();
            swap(a[i], b[i]);
            ans = min(ans, dis[0][N] + dis[1][1] + d[i]);
        }
    }
    if (ans >= 1e18) ans = -1;
    cout << ans << '\n';
    return 0;
}
