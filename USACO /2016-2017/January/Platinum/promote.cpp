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

int N, tin[MN], tout[MN], tt;
vi g[MN];

void ett(int u) {
    tin[u] = ++tt;
    for (int v : g[u]) ett(v);
    tout[u] = tt;
}

int b[MN];
void upd(int i) {
    for (; i < MN; i += i & -i) b[i]++;
}
int get(int i) {
    int r = 0;
    for (; i; i -= i & -i) r += b[i];
    return r;
}

int ans[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("promote");
    cin >> N;
    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        int p; cin >> p;
        v.eb(p, i);
    }
    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        g[p].pb(i);
    }
    ett(1);
    sort(all(v));
    reverse(all(v));
    for (pii p : v) {
        int u = p.second;
        ans[u] = get(tout[u]) - get(tin[u] - 1);
        upd(tin[u]);
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
    return 0;
}
