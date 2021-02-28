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
ll fp(ll x, ll y, ll m = MOD) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

ll inv(ll x) {
    return fp(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll num = 1, num2 = 1, sum = 1, prod = 1;
    for (int i = 0; i < n; i++) {
        ll p, a; cin >> p >> a;
        num = num * (a + 1) % MOD;
        sum = sum * (fp(p, a + 1) - 1) % MOD * inv(p - 1) % MOD;
        // prod_i = (prod_i-1)^(a+1) * (p^(0+1+2+...+a))^(num_i-1)
        // ^(a+1) for every power of p
        // ^(num_i-1) one power of p for every factor in the product
        prod = fp(prod, a + 1) * fp(fp(p, a * (a + 1) / 2), num2) % MOD;
        num2 = num2 * (a + 1) % (MOD - 1);
    }
    cout << num << " " << sum << " " << prod << '\n';
    return 0;
}
