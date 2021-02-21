#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
#define lc (i << 1)
#define rc (i << 1 | 1)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 3e4 + 5, MM = 55;
int B, N, D, c[MN], v[MN];
int t[MN * 2][MM];
int dp[MM];

void merge(int *f, int *g) {
    for (int i = B; i >= 0; i--)
        for (int j = 1; j <= i; j++)
            f[i] = max(f[i], f[i - j] + g[j]);
}

void build() {
    for (int i = N - 1; i; i--) {
        merge(t[i], t[lc]);
        merge(t[i], t[rc]);
    }
}

void upd(int i) {
    i += N - 1;
    memset(t[i], -1, sizeof(t[i])), t[i][0] = 0;
    t[i][c[i - N + 1]] = v[i - N + 1];
    for (i = i / 2; i; i /= 2) {
        memset(t[i], -1, sizeof(t[i])), t[i][0] = 0;
        merge(t[i], t[lc]);
        merge(t[i], t[rc]);
    }
}

int get(int l, int r) {
    r++;
    memset(dp, -1, sizeof(dp)), dp[0] = 0;
    for (l += N - 1, r += N - 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) merge(dp, t[l++]);
        if (r & 1) merge(dp, t[--r]);
    }
    return *max_element(dp, dp + B + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> B >> N >> D;
    memset(t, -1, sizeof(t));
    for (int i = 1; i <= 2 * N; i++) t[i][0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> c[i] >> v[i];
        t[i + N - 1][c[i]] = v[i];
    }
    build();
    for (int i = 0; i < D; i++) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        c[a] = b, upd(a);
        cout << get(x, y) << '\n';
    }
    return 0;
}
