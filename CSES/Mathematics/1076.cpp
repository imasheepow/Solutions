#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
ll f[2 * MN], finv[2 * MN];

ll fp(int x, int y, int m = MOD) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

ll c(int n, int k) {
    if (n < k) return 0;
    return f[n] * finv[k] % MOD * finv[n - k] % MOD;
}

void init(int n) {
    f[0] = 1;
    for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] * i % MOD;
    finv[2 * n] = fp(f[2 * n], MOD - 2);
    for (int i = 2 * n - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    init(1e6);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        cout << c(a, b) << '\n';
    }
    return 0;
}
