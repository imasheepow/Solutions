#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5;
ll N, a[22]; int K;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < K; i++) cin >> a[i];
    ll ans = 0;
    for (int msk = 1; msk < (1 << K); msk++) {
        ll val = 1;
        bool bad = false;
        for (int i = 0; i < K; i++) {
            if (msk & (1 << i)) {
                if ((__uint128_t) val * a[i] > N) {
                    bad = true; break;
                }
                val = val * a[i];
            }
        }
        if (bad) continue;
        if (__builtin_popcount(msk) & 1) ans += N / val;
        else ans -= N / val;
    }
    cout << ans << '\n';
    return 0;
}
