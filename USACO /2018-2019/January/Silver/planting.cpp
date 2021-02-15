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

int N;
int deg[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("planting");
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    int mx = 0;
    for (int i = 1; i <= N; i++) mx = max(mx, deg[i]);
    cout << mx + 1 << '\n';
    return 0;
}
