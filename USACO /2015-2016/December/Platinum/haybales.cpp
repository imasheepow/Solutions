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
const int MN = 2e5 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, Q, a[MN];
ll sum[MN * 4], mn[MN * 4], lz[MN * 4];

void push(int i, int l, int r) {
    if (lz[i]) {
        sum[i] += (r - l + 1) * lz[i];
        mn[i] += lz[i];
        if (l != r) {
            lz[lc] += lz[i];
            lz[rc] += lz[i];
        }
        lz[i] = 0;
    }
}

void build(int i, int l, int r) {
    if (l == r) {
        sum[i] = mn[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(lc, l, m), build(rc, m + 1, r);
    sum[i] = sum[lc] + sum[rc];
    mn[i] = min(mn[lc], mn[rc]);
}

void upd(int i, int l, int r, int ql, int qr, int v) {
    push(i, l, r);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) { lz[i] += v, push(i, l, r); return; }
    int m = (l + r) / 2;
    upd(lc, l, m, ql, qr, v), upd(rc, m + 1, r, ql, qr, v);
    sum[i] = sum[lc] + sum[rc];
    mn[i] = min(mn[lc], mn[rc]);
}

ll get1(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (l > qr || r < ql) return 1e18;
    if (l >= ql && r <= qr) return mn[i];
    int m = (l + r) / 2;
    return min(get1(lc, l, m, ql, qr), get1(rc, m + 1, r, ql, qr));
}

ll get2(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return sum[i];
    int m = (l + r) / 2;
    return get2(lc, l, m, ql, qr) + get2(rc, m + 1, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("haybales");
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    build(1, 1, N);
    for (int i = 0; i < Q; i++) {
        char op; int x, y, z; cin >> op >> x >> y;
        if (op == 'M') {
            cout << get1(1, 1, N, x, y) << '\n';
        } else if (op == 'S') {
            cout << get2(1, 1, N, x, y) << '\n';
        } else {
            cin >> z;
            upd(1, 1, N, x, y, z);
        }
    }
    return 0;
}
