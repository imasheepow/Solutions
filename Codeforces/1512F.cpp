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
int a[MN], b[MN];

void solve() {
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    ll ans = 1e9;
    ll cur = 0, days = 0;
    for (int i = 1; i <= n; i++) {
        ll x = (c - cur + a[i] - 1) / a[i];
        ans = min(ans, days + x);
        if (i == n) break;
        x = (b[i] - cur + a[i] - 1) / a[i];
        cur = cur + x * a[i] - b[i];
        days += x + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
