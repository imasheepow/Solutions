#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e3 + 5, MM = MN * MN;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, a[MN][MN], up[MM], down[MM], lft[MM], rht[MM];
int cnt[MM], ps[MN][MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("art");
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N * N; i++) {
        up[i] = 1e9, lft[i] = 1e9;
    }
    int num = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!a[i][j]) continue;
            int x = a[i][j];
            if (!cnt[x]) num++;
            cnt[x]++;
            up[x] = min(up[x], i);
            lft[x] = min(lft[x], j);
            down[x] = max(down[x], i);
            rht[x] = max(rht[x], j);
        }
    }
    if (num == 1) {
        cout << N * N - 1 << '\n';
        return 0;
    }
    for (int i = 1; i <= N * N; i++) {
        if (!cnt[i]) continue;
        ps[up[i]][lft[i]]++;
        ps[up[i]][rht[i] + 1]--;
        ps[down[i] + 1][lft[i]]--;
        ps[down[i] + 1][rht[i] + 1]++;
    }
    int sub = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            if (ps[i][j] >= 2) {
                // if >= 2 rects overlapping, the one visible is clearly not able to be painted first
                if (cnt[a[i][j]]) {
                    sub++;
                    cnt[a[i][j]] = 0;
                }
            }
        }
    }
    cout << N * N - sub << '\n';
    return 0;
}
