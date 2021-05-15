#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e3 + 5;
int n, a[MN];

int go(int l, int r, int x) {
    if (l > r) return 0;
    if (l == r) return a[l] != x;
    int p = l;
    for (int i = l; i <= r; i++) if (a[i] < a[p]) p = i;
    int ret = r - l + 1;
    ret = min(ret, go(l, p - 1, a[p]) + go(p + 1, r, a[p]) + a[p] - x);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << go(1, n, 0) << '\n';
    return 0;
}
