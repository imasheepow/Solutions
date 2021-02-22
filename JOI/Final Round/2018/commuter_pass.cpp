#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
using vi = vector<int>;
const int MN = 1e5 + 5;
int N, M, S, T, A, B; // stab O_O
vector<pii> g[MN];
ll disA[MN], disB[MN], disS[MN], disT[MN];
ll dp[MN][4];
 
void dijk(ll *dis, int st) {
    for (int i = 1; i <= N; i++) dis[i] = 1e18;
    dis[st] = 0;
    priority_queue<pii, vector<pii>, greater<>> q;
    q.emplace(0, st);
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
    cin >> N >> M >> S >> T >> A >> B;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    dijk(disS, S), dijk(disT, T), dijk(disA, A), dijk(disB, B);
    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        v.eb(disS[i], i);
        for (int j = 0; j <= 3; j++) dp[i][j] = 1e18;
    }
    sort(all(v));
    ll mn = disS[T], ans = disA[B];
    for (auto [d, u] : v) {
        dp[u][1] = min(dp[u][1], disA[u]);
        dp[u][2] = min(dp[u][2], disB[u]);
        for (auto [v, w] : g[u]) {
            if (d + w + disT[v] == mn) {
                dp[v][1] = min(dp[v][1], dp[u][1]);
                dp[v][2] = min(dp[v][2], dp[u][2]);
                dp[v][3] = min(dp[v][3], dp[v][1] + disB[v]);
                dp[v][3] = min(dp[v][3], dp[v][2] + disA[v]);
                ans = min(ans, dp[v][3]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
