#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e6 + 5;
int N, Q;

template <typename T> struct SegmentTree {
#define lc (i << 1)
#define rc (i << 1 | 1)
    T t[MN * 4], lz[MN * 4], lz2[MN * 4];
    const T ID = 0;
    T merge(T x, T y) { return x + y; }
    void push(int i, int l, int r) {
        int m = (l + r) / 2;
        if (lz[i]) {
            t[i] += lz[i] * (r - l + 1);
            if (l != r) {
                lz[lc] += lz[i];
                lz[rc] += lz[i];
            }
            lz[i] = 0;
        }
        if (lz2[i]) {
            t[i] += lz2[i] * (r - l + 1) * (r - l + 2) / 2;
            if (l != r) {
                lz2[lc] += lz2[i];
                lz2[rc] += lz2[i];
                lz[rc] += lz2[i] * (m - l + 1);
            }
            lz2[i] = 0;
        }
    }
    void build(int i = 1, int l = 0, int r = N - 1) {
        lz[i] = -1;
        if (l == r) { t[i] = 0; return; }
        int m = (l + r) / 2;
        build(lc, l, m), build(rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    void upd(int x, int v, int i = 1, int l = 0, int r = N - 1) {
        if (l == r) { t[i] = v; return; }
        int m = (l + r) / 2;
        if (x <= m) upd(x, v, lc, l, m);
        else upd(x, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    void prop(int ql, int qr, int v, int i = 1, int l = 0, int r = N - 1) {
        push(i, l, r);
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            lz[i] = v * (l - ql), lz2[i] = v, push(i, l, r); return;
        }
        int m = (l + r) / 2;
        prop(ql, qr, v, lc, l, m), prop(ql, qr, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    T get(int ql, int qr, int i = 1, int l = 0, int r = N - 1) {
        push(i, l, r);
        if (l > qr || r < ql) return ID;
        if (l >= ql && r <= qr) return t[i];
        int m = (l + r) / 2;
        return merge(get(ql, qr, lc, l, m), get(ql, qr, rc, m + 1, r));
    }
};
SegmentTree<ll> seg;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int t, l, r, v; cin >> t >> l >> r; l--, r--;
        if (t == 1) {
            cin >> v;
            seg.prop(l, r, v);
        } else {
            cout << seg.get(l, r) << '\n';
        }
    }
    return 0;
}
