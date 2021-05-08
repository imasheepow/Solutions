#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5, MC = 4e5 + 5;
int N;
vi g[MC];
int cnt1, cnt2;
bool vis[MC];

void dfs(int u) {
    vis[u] = true;
    cnt1++;
    for (int v : g[u]) {
        cnt2++;
        if (v == u) cnt2++;
        if (!vis[v]) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= 4e5; i++) {
        if (vis[i]) continue;
        cnt1 = cnt2 = 0;
        dfs(i);
        cnt2 /= 2;
        ans += cnt1 - (cnt2 >= cnt1 ? 0 : 1);
    }
    cout << ans << '\n';
    return 0;
}
