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
int a, b, p; ll n;

ll fp(int x, int y, int m = p) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

ll inv(int x) {
    return fp(x, p - 2, p);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b >> p >> n;
    ll ans = 0;
    for (int r = 0; r < p - 1; r++) {
        ll v = b * inv(fp(a, r)) % p;
        ll q = (r - v + p) % p;
        cout << r << " " << v << " " << q << '\n';
        ll x = (p - 1) * q + r;
        if (x > n) continue;
        // (p-1)(q+pk)+r <= n
        // (p-1)q+r + p(p-1)k <= n
        // x + p(p-1)k <= n
        ans += (n - x) / (p * 1LL * (p - 1)) + 1;
    }
    cout << ans << '\n';
    return 0;
}
