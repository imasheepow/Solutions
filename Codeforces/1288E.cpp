#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 3e5 + 5, MM = MN * 2;

/*
 * observations:
 * mn[i] = i or 1
 * u only need to check mx when moving to pos 1 or when all moves are done
 */
int n, m, mn[MN], mx[MN], pos[MN], b[MM];

void upd(int i, int v) {
    for (; i < MM; i += i & -i) b[i] += v;
}

int get(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mn[i] = mx[i] = i;
        pos[i] = i + m; // initially store from [1+m,n+m]
        upd(pos[i], 1);
    }
    int cur = m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        mn[x] = 1;
        mx[x] = max(mx[x], get(pos[x]));
        upd(pos[x], -1);
        upd(pos[x] = cur--, 1);
    }
    for (int i = 1; i <= n; i++) {
        mx[i] = max(mx[i], get(pos[i]));
        cout << mn[i] << " " << mx[i] << '\n';
    }
    return 0;
}
