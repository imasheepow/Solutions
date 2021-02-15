#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e3 + 5, MOD = 1e9 + 7;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, K;
int a[MN];
vector<int> c[MN];
int cnt[26];
int dp[MN]; // standard dp
int dp2[MN]; // number of ways to end a line with a specific rhyme class

ll fp(int x, int y, int m = MOD) {
    ll ret = 1;
    for (x %= m; y > 0; y >>= 1, x = (x * 1LL * x) % m)
        if (y & 1) ret = (ret * x) % m;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("poetry");
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        int b; cin >> a[i] >> b;
        c[b].pb(i);
    }
    for (int i = 0; i < M; i++) {
        char e; cin >> e;
        cnt[e - 'A']++;
    }
    dp[0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j : c[i]) {
            dp2[i] = (dp2[i] + dp[K - a[j]]) % MOD;
        }
    }
    int ans = 1;
    for (int i = 0; i < 26; i++) {
        if (!cnt[i]) continue;
        int mul = 0;
        for (int j = 1; j <= N; j++) {
            // choose rhyming class for a character
            mul = (mul + fp(dp2[j], cnt[i])) % MOD;
        }
        ans = (ans * 1LL * mul) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
