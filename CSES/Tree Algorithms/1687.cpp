#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5, LN = 18;
int N, Q, up[MN][LN];
vi g[MN];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int j = 1; j < LN; j++)
        if (up[u][j - 1]) up[u][j] = up[up[u][j - 1]][j - 1];
        else break;
    for (int v : g[u]) if (v != p)
        dfs(v, u);
}

int qry(int u, int k) {
    for (int j = LN - 1; j >= 0; j--)
        if (k & (1 << j)) u = up[u][j], k -= (1 << j);
    if (!u) return -1;
    return u;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        g[p].pb(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= Q; i++) {
        int u, k; cin >> u >> k;
        cout << qry(u, k) << '\n';
    }
    return 0;
}
