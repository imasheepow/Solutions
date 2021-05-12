#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5;

int k1, k2, k3, a[MN];
int ps[3][MN], mn[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    for (int i = 1; i <= k1; i++) {
        int x; cin >> x;
        a[x] = 0;
    }
    for (int i = 1; i <= k2; i++) {
        int x; cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= k3; i++) {
        int x; cin >> x;
        a[x] = 2;
    }
    for (int i = 1; i <= n; i++) {
        ps[a[i]][i]++;
        for (int j = 0; j < 3; j++) {
            ps[j][i] += ps[j][i - 1];
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        if (i) mn[i] = min(mn[i - 1], -ps[0][i] + ps[1][i]);
        ans = min(ans, ps[2][i] + ps[1][n] - ps[1][i] + ps[0][n] + mn[i]);
    }
    cout << ans << '\n';
    return 0;
}
