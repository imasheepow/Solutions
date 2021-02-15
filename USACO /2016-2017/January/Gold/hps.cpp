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
int N, K, ps[3][MN], mx[3][MN], dp[25][MN];

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("hps");
    cin >> N >> K; K++;
    for (int i = 1; i <= N; i++) {
        char c; cin >> c;
        if (c == 'H') ps[0][i]++;
        else if (c == 'P') ps[1][i]++;
        else ps[2][i]++;
        for (int j = 0; j < 3; j++) ps[j][i] += ps[j][i - 1];
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[k][i] = max(dp[k][i], ps[j][i] + mx[j][i - 1]);
                mx[j][i] = max(mx[j][i - 1], dp[k - 1][i] - ps[j][i]);
            }
        }
    }
    cout << dp[K][N] << '\n';
    return 0;
}
