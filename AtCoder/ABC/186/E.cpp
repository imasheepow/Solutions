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

pii xgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [x, y] = xgcd(b, a % b);
    return {y, x - (a / b) * y};
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        ll N, S, K; cin >> N >> S >> K;
        S = (-S % N + N) % N;
        int d = gcd(gcd(N, S), K);
        N /= d, S /= d, K /= d;
        d = gcd(K, N);
        if (d != 1) {
            cout << -1 << '\n';
            continue;
        }
        auto [x, y] = xgcd(K, N); x %= N;
        cout << (x * S % N + N) % N << '\n';
    }
    return 0;
}
