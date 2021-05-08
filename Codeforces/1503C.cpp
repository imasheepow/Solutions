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
int a[MN], c[MN], ord[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        ord[i] = i;
    }
    sort(ord, ord + n, [](int i, int j) {
       return a[i] < a[j];
    });
    int mx = a[ord[0]] + c[ord[0]];
    for (int i = 0; i < n; i++) {
        ans += max(0, a[ord[i]] - mx) + c[ord[i]];
        mx = max(mx, a[ord[i]] + c[ord[i]]);
    }
    cout << ans << '\n';
    return 0;
}
