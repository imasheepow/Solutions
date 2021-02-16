#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e4 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, T;
int c[MN];
vector<pii> g[MN];
int dis[MN], par[MN];
ll mul[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("shortcut");
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    for (int i = 1; i <= N; i++) dis[i] = par[i] = 1e9;
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                par[v] = u;
                q.emplace(dis[v], v);
            } else if (dis[v] == dis[u] + w) {
                par[v] = min(par[v], u);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        mul[i] += c[i];
        int cur = par[i];
        while (cur != 1) {
            mul[cur] += c[i];
            cur = par[cur];
        }
    }
    ll mx = 0;
    for (int i = 2; i <= N; i++) {
        mx = max(mx, mul[i] * (dis[i] - T));
    }
    cout << mx << '\n';
    return 0;
}
