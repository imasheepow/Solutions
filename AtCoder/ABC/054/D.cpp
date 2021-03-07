#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 45;
int N, Ma, Mb;
int a[MN], b[MN], c[MN];
int dp[405][405];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Ma >> Mb;
    for (int i = 1; i <= N; i++) cin >> a[i] >> b[i] >> c[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 400; j >= a[i]; j--) {
            for (int k = 400; k >= b[i]; k--) {
                dp[j][k] = min(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; Ma * i <= 400 && Mb * i <= 400; i++) {
        ans = min(ans, dp[Ma * i][Mb * i]);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
    return 0;
}
