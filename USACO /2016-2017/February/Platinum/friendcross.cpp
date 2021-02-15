#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, MM = 1.4e7;
int N, K, xs[MN], ys[MN];
int rt[MN], ls[MM], rs[MM], ndc, sum[MM];

void upd(int &i, int l, int r, int x, int v) {
    if (!i) i = ++ndc;
    if (l == r) { sum[i] += v; return; }
    int m = (l + r) / 2;
    if (x <= m) upd(ls[i], l, m, x, v);
    else upd(rs[i], m + 1, r, x, v);
    sum[i] = sum[ls[i]] + sum[rs[i]];
}

int get(int &i, int l, int r, int ql, int qr) {
    if (!i || l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return sum[i];
    int m = (l + r) / 2;
    if (qr <= m) return get(ls[i], l, m, ql, qr);
    else if (ql > m) return get(rs[i], m + 1, r, ql, qr);
    else return get(ls[i], l, m, ql, qr) + get(rs[i], m + 1, r, ql, qr);
}

void modify(int x, int y, int v) {
    for (; x <= N; x += x & -x) upd(rt[x], 1, N, y, v);
}

int qry(int x, int y, int mul) {
    int ret = 0;
    for (; x; x -= x & -x) ret += mul * get(rt[x], 1, N, 1, y);
    return ret;
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("friendcross");
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        xs[a] = i;
    }
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        ys[a] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += qry(xs[i], N, 1);
        ans += qry(N, ys[i], 1);
        ans -= qry(xs[i], ys[i], 2);
        if (i - K > 0) modify(xs[i - K], ys[i - K], 1);
    }
    cout << ans << '\n';
    return 0;
}
