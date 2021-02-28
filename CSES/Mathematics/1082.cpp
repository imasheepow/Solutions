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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n; cin >> n;
    ll cur = 1, ans = 0;
    while (cur <= n) {
        cout << cur << '\n';
        ll div = n / cur, nxt = n / div + 1;
        ll num = nxt - cur, sum = cur + nxt - 1;
        if (num % 2 == 0) num /= 2;
        else sum /= 2;
        num %= MOD, sum %= MOD, div %= MOD;
        ans = (ans + num * sum % MOD * div % MOD) % MOD;
        cur = nxt;
    }
    cout << ans << '\n';
    return 0;
}
