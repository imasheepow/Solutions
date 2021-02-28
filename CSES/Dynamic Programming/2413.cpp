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
ll dp[MN][2];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
    return 0;
}
