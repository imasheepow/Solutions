#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e5 + 5;

int n, k, d, a[MN], dp[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    dp[0] = 1;
    int sum = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j < i && a[i] - a[j] > d) sum -= dp[j - 1], j++;
        if (i - k >= 0) sum += dp[i - k];
        dp[i] = sum >= 1;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
    return 0;
}
