#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, MOD = 1e9 + 7;
ll fp(int x, int y, int m = MOD) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + fp(m, gcd(i, n))) % MOD;
    }
    ans = ans * fp(n, MOD - 2) % MOD;
    cout << ans << '\n';
    return 0;
}