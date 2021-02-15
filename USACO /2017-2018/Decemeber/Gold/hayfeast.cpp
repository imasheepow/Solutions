#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, LN = 17;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, s[MN][LN];
ll M, ps[MN];

int get(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(s[l][k], s[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("hayfeast");
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> ps[i] >> s[i][0];
        ps[i] += ps[i - 1];
    }
    for (int j = 1; j < LN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            s[i][j] = max(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= N; i++) {
        int j = lower_bound(ps + i + 1, ps + N + 1, ps[i] + M) - ps;
        if (j > N) continue;
        ans = min(ans, get(i + 1, j));
    }
    cout << ans << '\n';
    return 0;
}
