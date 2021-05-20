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

int N, Q, a[MN], pre[MN];
map<int, bool> mp;

template <typename T> struct SegmentTree {
#define lc (i << 1)
#define rc (i << 1 | 1)
    T t[MN * 4];
    const T ID = 0;
    T merge(T x, T y) { return max(x, y); }
    void upd(int x, int v, int i = 1, int l = 1, int r = N) {
        if (l == r) { t[i] = v; return; }
        int m = (l + r) / 2;
        if (x <= m) upd(x, v, lc, l, m);
        else upd(x, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    T get(int ql, int qr, int i = 1, int l = 1, int r = N) {
        if (l > qr || r < ql) return ID;
        if (l >= ql && r <= qr) return t[i];
        int m = (l + r) / 2;
        return merge(get(ql, qr, lc, l, m), get(ql, qr, rc, m + 1, r));
    }
};
SegmentTree<int> seg;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int r = 1, l = 1; r <= N; r++) {
        cin >> a[r];
        while (mp[a[r]]) {
            mp[a[l]] = 0;
            l++;
        }
        mp[a[r]] = 1;
        pre[r] = l;
        seg.upd(r, r - l + 1);
    }
    int ans = 0;
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        l ^= ans, r ^= ans;
        if (pre[r] > l) {
            cout << (ans = 0) << '\n';
            continue;
        }
        int lo = r, hi = N + 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (pre[mi] > l) hi = mi;
            else lo = mi + 1;
        }
        cout << (ans = seg.get(r, lo - 1)) << '\n';
    }
    return 0;
}
