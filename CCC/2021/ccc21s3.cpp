#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
const int MN = 1e6 + 5;
int N;
int p[MN], w[MN], d[MN];

ll f(int c) {
    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        if (p[i] >= c - d[i] && p[i] <= c + d[i]) continue;
        if (p[i] > c + d[i]) ret += (p[i] - (c + d[i])) * 1LL * w[i];
        else ret += ((c - d[i]) - p[i]) * 1LL * w[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i] >> w[i] >> d[i];
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (f(m) < f(m + 1)) r = m;
        else l = m + 1;
    }
    cout << f(l) << '\n';
    return 0;
}
