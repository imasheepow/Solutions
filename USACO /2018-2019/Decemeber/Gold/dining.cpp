#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e4 + 5;
int N, M, K, dis1[MN], dis2[MN];
vector<pii> g[MN];

void dijk(int s, int *dis) {
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(dis[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    memset(dis1, 0x3f, sizeof(dis1));
    dijk(N, dis1);
    for (int i = 0; i < K; i++) {
        int u, x; cin >> u >> x;
        g[N + 1].emplace_back(u, dis1[u] - x);
    }
    memset(dis2, 0x3f, sizeof(dis2));
    dijk(N + 1, dis2);
    for (int i = 1; i < N; i++) {
        cout << (dis2[i] <= dis1[i]) << '\n';
    }
    return 0;
}
