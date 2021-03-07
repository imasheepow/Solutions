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
int N, M, Q;
vector<ll> s, t;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        s.pb(x);
    }
    s.pb(-1e18), s.pb(1e18);
    for (int i = 0; i < M; i++) {
        ll x; cin >> x;
        t.pb(x);
    }
    t.pb(-1e18), t.pb(1e18);
    sort(all(s)), sort(all(t));
    for (int i = 0; i < Q; i++) {
        ll x; cin >> x;
        ll ans = 1e18;
        int a = upper_bound(all(s), x) - s.begin();
        int b = upper_bound(all(t), x) - t.begin();
        for (int j = a - 1; j <= a; j++) {
            for (int k = b - 1; k <= b; k++) {
                ll d1 = abs(x - s[j]) + abs(s[j] - t[k]);
                ll d2 = abs(x - t[k]) + abs(t[k] - s[j]);
                ans = min(ans, min(d1, d2));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
