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
int N, h[MN], l[MN], r[MN];
vector<int> cc;
int b[MN];
void upd(int i, int v) {
    for (; i < MN; i += i & -i) b[i] += v;
}
int get(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret += b[i];
    return ret;
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("bphoto");
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
        cc.pb(h[i]);
    }
    sort(all(cc));
    cc.erase(unique(all(cc)), end(cc));
    for (int i = 1; i <= N; i++) {
        h[i] = lower_bound(all(cc), h[i]) - begin(cc) + 1;
    }
    for (int i = 1; i <= N; i++) {
        l[i] = get(1e5) - get(h[i]);
        upd(h[i], 1);
    }
    memset(b, 0, sizeof(b));
    for (int i = N; i >= 1; i--) {
        r[i] = get(1e5) - get(h[i]);
        upd(h[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (max(l[i], r[i]) > 2 * min(l[i], r[i])) ans++;
    }
    cout << ans << '\n';
    return 0;
}
