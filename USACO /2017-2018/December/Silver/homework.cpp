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
int N, a[MN], ps[MN], mn[MN];

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("homework");
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];
    mn[N + 1] = 1e9;
    for (int i = N; i >= 1; i--) mn[i] = min(mn[i + 1], a[i]);
    double mx = 0;
    vi ids;
    for (int i = 1; i <= N - 2; i++) {
        double cur = (ps[N] - ps[i] - mn[i + 1]) / (1.0 * (N - i - 1));
        if (mx < cur) {
            mx = cur;
            ids.clear();
            ids.pb(i);
        } else if (abs(mx - cur) < 1e-11) {
            ids.pb(i);
        }
    }
    for (int i : ids) cout << i << '\n';
    return 0;
}
