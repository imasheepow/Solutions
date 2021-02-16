#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 3e5 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, K, a[MN], dp[MN];
/*
 * h[i] is count of holsteins and g[i] is count of guernseys.
 * a subarray [j+1,i] will have tie or majority guernsey if
 * g[i]-g[j] >= h[i]-h[j]
 * h[i]-g[i] <= h[j]-g[j]
 * if we let a[i] = h[i]-g[i];
 * cost(j+1,i) = 1 if a[i] <= a[j]
 *             = 0 if a[i] > a[j]
 *
 * min dp[j] <= dp[i] <= min dp[j]+1
 */
multiset<int> dat[MN]; // stores all the a[i] values for a specific dp value

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("redistricting");
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        char c; cin >> c;
        if (c == 'H') a[i]++;
        else a[i]--;
        a[i] += a[i - 1];
    }
    multiset<int> vals;
    vals.insert(0);
    dat[0].insert(0);
    for (int i = 1; i <= N; i++) {
        int mn = *vals.begin();
        if (*dat[mn].begin() < a[i]) dp[i] = mn;
        else dp[i] = mn + 1;
        vals.insert(dp[i]);
        dat[dp[i]].insert(a[i]);
        if (i >= K) {
            vals.erase(vals.find(dp[i - K]));
            dat[dp[i - K]].erase(dat[dp[i - K]].find(a[i - K]));
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
