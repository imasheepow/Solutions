#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 105, MM = 505, INF = 1e9;
int N, L, a[MN], c[MN];
// c1(c-c1)/w1(w-w1), for fixed w1 is minimal when c1 is minimal
int dp[MN][MM];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> L;
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= N; i++) cin >> a[i], sum1 += a[i];
    for (int i = 1; i <= N; i++) cin >> c[i], sum2 += c[i];
    for (int i = 0; i <= N; i++) fill(dp[i], dp[i] + MM, INF);
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= 1; j--) {
            for (int k = a[i]; k <= sum1; k++) {
                dp[j][k] = min(dp[j][k], dp[j - 1][k - a[i]] + c[i]);
            }
        }
    }
    double ans = 1e18;
    for (int i = 1; i <= sum1; i++) {
        int val = min(dp[L][i], dp[N - L][i]);
        if (val == INF) continue;
        ans = min(ans, val * (sum2 - val) * 1.0 / (i * (sum1 - i)));
    }
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}
