#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
const int MN = 1e5 + 5;

pair<ll, ll> xgcd(ll a, ll b) {
    if (b == 0) return {1, 0};
    auto [x, y] = xgcd(b, a % b);
    return {y, x - (a / b) * y};
}

pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
    ll d = gcd(m1, m2);
    if (a1 % d != a2 % d) return {-1, -1};
    auto [x, y] = xgcd(m1, m2);
    ll mod = m1 / d * m2;
    a1 += m1 * ((a2 - a1) / d * x % (m2 / d));
    return {(a1 % mod + mod) % mod, mod};
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int X, Y, P, Q; cin >> X >> Y >> P >> Q;
        ll ans = 4e18;
        ll m1 = 2 * (X + Y), m2 = P + Q;
        for (int t1 = X; t1 < X + Y; t1++) {
            for (int t2 = P; t2 < P + Q; t2++) {
                auto [a, m] = crt(t1, m1, t2, m2);
                if (a == -1) continue;
                ans = min(ans, a);
            }
        }
        if (ans == 4e18) cout << "infinity\n";
        else cout << ans << '\n';
    }
    return 0;
}
