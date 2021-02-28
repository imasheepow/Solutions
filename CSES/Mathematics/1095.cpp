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
ll fp(int x, int y, int m = MOD) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        cout << fp(a, b) << '\n';
    }
    return 0;
}
