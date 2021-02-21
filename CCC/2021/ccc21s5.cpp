#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 150000 + 5, LN = 18;
int N, M, a[MN], b[MN], c[MN];
int val[1 << 16], st[MN][LN], cnt[MN];
vi v[MN];
int ans[MN];

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

void init() {
    for (int i = 1; i < (1 << 16); i++) {
        int x = 1;
        for (int j = 0; j < 16; j++) {
            if (i & (1 << j)) x = lcm(x, j + 1);
        }
        val[i] = x;
    }
}

int get(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        v[a[i]].pb(c[i]);
        v[b[i] + 1].pb(-c[i]);
    }
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        sort(all(v[i]));
        for (int j : v[i]) {
            if (j > 0) {
                if (cnt[j] == 0) cur += 1 << (j - 1);
                cnt[j]++;
            } else {
                j = -j;
                cnt[j]--;
                if (cnt[j] == 0) cur -= 1 << (j - 1);
            }
        }
        if (!cur) ans[i] = 1;
        else ans[i] = val[cur];
        st[i][0] = ans[i];
    }
    for (int j = 1; j < LN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 0; i < M; i++) {
        if (get(a[i], b[i]) != c[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
    return 0;
}
