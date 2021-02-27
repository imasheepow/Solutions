#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, MM = 1e6 + 5;
int N, a[MN];
ll cnt[MM], dp[MM];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1e6; i >= 1; i--) {
        ll tot = 0;
        for (int j = i; j <= 1e6; j += i) tot += cnt[j], dp[i] -= dp[j];
        dp[i] += tot * (tot - 1) / 2;
    }
    cout << dp[1] << '\n';
    return 0;
}
