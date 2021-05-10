#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5 + 5;
int n, a[MN], b[MN]; char s[MN];
vector<int> g[26];
void upd(int i) {
    for (; i < MN; i += i & -i) b[i]++;
}
int get(int i) {
    int r = 0;
    for (; i; i -= i & -i) r += b[i];
    return r;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) g[s[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++) {
        int k = g[i].size() - 1;
        for (int j = 0; j < g[i].size(); j++)
            a[g[i][j]] = n - g[i][k--] + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += get(2e5) - get(a[i]);
        upd(a[i]);
    }
    cout << ans << '\n';
    return 0;
}

