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
int N, W, D;
vi g[MN];
int dis[MN], val[MN], p[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> W >> D;
    for (int i = 0; i < W; i++) {
        int u, v; cin >> u >> v;
        g[v].pb(u);
    }
    for (int i = 1; i <= N; i++) dis[i] = 1e9;
    dis[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    multiset<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        val[i] += i - 1 + dis[p[i]];
        s.insert(val[i]);
    }
    for (int i = 0; i < D; i++) {
        int x, y; cin >> x >> y;
        s.erase(s.find(val[x])), s.erase(s.find(val[y]));
        swap(p[x], p[y]);
        val[x] = x - 1 + dis[p[x]];
        val[y] = y - 1 + dis[p[y]];
        s.insert(val[x]), s.insert(val[y]);
        cout << *s.begin() << '\n';
    }
    return 0;
}
