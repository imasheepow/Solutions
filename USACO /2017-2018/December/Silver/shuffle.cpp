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

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, to[MN], in[MN];
bool vis[MN];
int ans;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    in[to[u]]--;
    if (!in[to[u]]) dfs(to[u]);
}

void go(int u) {
    for (int v = to[u]; ; v = to[v]) {
        ans++;
        vis[v] = true;
        if (v == u) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("shuffle");
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> to[i], in[to[i]]++;
    for (int i = 1; i <= N; i++) if (!in[i]) dfs(i);
    for (int i = 1; i <= N; i++) if (!vis[i]) go(i);
    cout << ans << '\n';
    return 0;
}
