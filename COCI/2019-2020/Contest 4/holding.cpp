#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 105;
int N, L, R, K, v[MN];
// two sets [L,R] and the complement. swapping elements shouldn't cross.
int dp[2][MN][MN * MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> L >> R >> K;
    int sum = 0;
    vector<int> a, b;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        if (L <= i && i <= R) a.pb(i), sum += v[i];
        else b.pb(i);
    }
    dp[0][0][0] = 0;
    int c = 0, p = 1;
    for (int i = 1; i <= sz(a); i++) {
        swap(c, p);
        for (int j = 1; j <= sz(b); j++) {
            int need = abs(a[i - 1] - b[j - 1]);
            for (int k = 0; k <= K; k++) {
                dp[c][j][k] = min(dp[p][j][k], dp[c][j - 1][k]);
                if (k >= need) dp[c][j][k] = min(dp[c][j][k], dp[p][j - 1][k - need] - v[a[i - 1]] + v[b[j - 1]]);
            }
        }
    }
    cout << sum + dp[c][sz(b)][K] << '\n';
    return 0;
}
