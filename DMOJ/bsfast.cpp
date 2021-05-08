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
    T t[MN * 4];
    const T ID = 2e9;
    T merge(T x, T y) { return min(x, y); }
    void upd(int x, int v, int i = 1, int l = 1, int r = N) {
        if (l == r) { t[i] = v; return; }
        int m = (l + r) / 2;
        if (x <= m) upd(x, v, lc, l, m);
        else upd(x, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    int walk(int k, int ql, int qr, int i = 1, int l = 1, int r = N) {
        if (t[i] >= k || r < ql) return -1;
        int m = (l + r) / 2;
        if (l == r) return l;
        int ret = walk(k, ql, qr, lc, l, m);
        if (ret == -1) ret = walk(k, ql, qr, rc, m + 1, r);
        return ret;
    }
};
SegmentTree<int> seg;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        seg.upd(i, a);
    }
    int ans = 0;
    for (int i = 0; i < Q; i++) {
        int tp, x, y, z;
        cin >> tp >> x >> y;
        x ^= ans, y ^= ans;
        if (tp == 1) seg.upd(x, y);
        else {
            cin >> z; z ^= ans;
            ans = seg.walk(z, x, y);
            cout << ans << '\n';
        }
    }
    return 0;
}
