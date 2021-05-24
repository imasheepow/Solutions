#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5;

int N, M, Q;
int a[MN], num[MN];
vi b[MN];

template<typename T> struct SegmentTree {
#define lc (i << 1)
#define rc (i << 1 | 1)
    T t[MN * 4], lz[MN * 4];
    const T ID = 2e9;
    T merge(T x, T y) { return min(x, y); }
    void push(int i, int l, int r) {
        if (lz[i]) {
            t[i] += lz[i];
            if (l != r) {
                lz[lc] += lz[i];
                lz[rc] += lz[i];
            }
            lz[i] = 0;
        }
    }
    void upd(int ql, int qr, int v, int i = 1, int l = 1, int r = M) {
        push(i, l, r);
        if (l > qr || r < ql || ql > qr) return;
        if (l >= ql && r <= qr) {
            lz[i] += v, push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        upd(ql, qr, v, lc, l, m), upd(ql, qr, v, rc, m + 1, r);
        t[i] = merge(t[lc], t[rc]);
    }
    T get(int ql, int qr, int i = 1, int l = 1, int r = M) {
        push(i, l, r);
        if (l > qr || r < ql) return ID;
        if (l >= ql && r <= qr) return t[i];
        int m = (l + r) / 2;
        return merge(get(ql, qr, lc, l, m), get(ql, qr, rc, m + 1, r));
    }
};
SegmentTree<int> seg;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    int R = a[1], sum = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] >= R) sum++;
    }
    for (int i = 1; i <= M; i++) {
        cin >> num[i];
        b[i].resize(num[i] + 1);
        for (int j = 1; j <= num[i]; j++) {
            cin >> b[i][j];
        }
        seg.upd(i, i, N - num[i] - sum);
        for (int j = 1; j <= num[i]; j++) {
            if (b[i][j] > R) sum++;
        }
    }
    for (int i = 0; i < Q; i++) {
        int x, y, z; cin >> x >> y >> z;
        bool cmp1 = b[x][y] > R;
        bool cmp2 = z > R;
        b[x][y] = z;
        if (cmp1 != cmp2) {
            if (cmp1) {
                seg.upd(x + 1, M, 1);
            } else {
                seg.upd(x + 1, M, -1);
            }
        }
        int mn = seg.get(1, M);
        cout << (mn >= 0) << '\n';
    }
    return 0;
}
