#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 205;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, a[MN][MN], ps[MN][MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("fortmoo");
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c; cin >> c;
            a[i][j] = (c == 'X');
            ps[i][j] += a[i][j] + ps[i][j - 1];
        }
    }
    int ans = 0;
    for (int j = 1; j <= M; j++) {
        for (int k = j; k <= M; k++) {
            int lst = -1;
            for (int i = 1; i <= N; i++) {
                if (a[i][j] || a[i][k]) {
                    lst = -1;
                    continue;
                }
                int sum = ps[i][k] - ps[i][j - 1];
                if (sum) continue;
                if (lst == -1) lst = i;
                else ans = max(ans, (k - j + 1) * (i - lst + 1));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
