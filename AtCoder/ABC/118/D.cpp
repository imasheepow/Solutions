#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e4 + 5;
int N, M, a[10];
int cst[] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> a[i];
    sort(a, a + M, greater<>());
    fill(dp, dp + N + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (i >= cst[a[j]]) {
                dp[i] = max(dp[i], dp[i - cst[a[j]]] + 1);
            }
        }
    }
    int cur = N;
    for (int i = 0; i < dp[N]; i++) {
        for (int j = 0; j < M; j++) {
            if (cur >= cst[a[j]] && dp[cur - cst[a[j]]] == dp[cur] - 1) {
                cout << a[j];
                cur -= cst[a[j]];
                break;
            }
        }
    }
    return 0;
}
