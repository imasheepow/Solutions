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

int N, Q, a[MN], b[MN], pre[MN], ans[MN];
map<int, int> lst;

void upd(int i, int x) {
    for (; i < MN; i += i & -i) b[i] ^= x;
}

int get(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret ^= b[i];
    return ret;
}

struct Query {
    int l, r, idx;
};
Query qs[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }
    sort(qs, qs + Q, [](Query &a, Query &b) {
       return a.r < b.r;
    });
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        upd(i, a[i]);
        if (lst[a[i]]) upd(lst[a[i]], a[i]);
        lst[a[i]] = i;
        while (pos < Q && qs[pos].r == i) {
            auto [l, r, idx] = qs[pos];
            ans[idx] = get(r) ^ get(l - 1) ^ pre[r] ^ pre[l - 1];
            pos++;
        }
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
    return 0;
}
