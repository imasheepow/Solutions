#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e5 + 5;

int N, Q, a[MN];

struct Node {
    int mn, idx;
    Node() : mn(1e9), idx(-1) {}
    Node(int v, int i) : mn(v), idx(i) {}
    Node(Node l, Node r) {
        mn = min(l.mn, r.mn);
        if (mn == l.mn) idx = l.idx;
        else idx = r.idx;
    }
};

template <typename T> struct SegmentTree {
#define lc (i << 1)
#define rc (i << 1 | 1)
    T t[MN * 4];
    const T ID = Node();
    T merge(T x, T y) { return Node(x, y); }
    void build(int i = 1, int l = 1, int r = N) {
        if (l == r) { t[i] = Node(); return; }
        int m = (l + r) / 2;
        build(lc, l, m), build(rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    void upd(int x, int v, int i = 1, int l = 1, int r = N) {
        if (l == r) { t[i] = Node(v, x); return; }
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
SegmentTree<Node> seg;

struct Query {
    int l, r, idx;
    bool operator<(const Query &o) const { return r < o.r; }
} qs[MN];

int lst[MN], ans[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }
    sort(qs, qs + Q);
    int pos = 0;
    seg.build();
    for (int i = 1; i <= N; i++) {
        seg.upd(i, lst[a[i]]);
        if (lst[a[i]]) seg.upd(lst[a[i]], 1e9);
        lst[a[i]] = i;
        while (pos < Q && qs[pos].r == i) {
            auto [mn, idx] = seg.get(qs[pos].l, i);
            if (mn < qs[pos].l) ans[qs[pos].idx] = a[idx];
            pos++;
        }
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
    return 0;
}
