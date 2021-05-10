#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 505;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int num = r - l + 1;
    int lo = 0, hi = 0;
    for (int i = 1; i <= num; i++) lo += i;
    for (int i = n; i > n - num; i--) hi += i;
    if (lo <= s && s <= hi) {
        set<int> dat;
        for (int i = 1; i <= n; i++) dat.insert(i);
        vi v;
        for (int i = num; i >= 1; i--) v.pb(i), s -= i;
        for (int i = 0; i < num; i++) {
            while (s > 0 && v[i] < n - i) s--, v[i]++;
            dat.erase(v[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (l <= i && i <= r) {
                cout << v.back() << " ";
                v.pop_back();
            } else {
                cout << *dat.begin() << " ";
                dat.erase(dat.begin());
            }
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
