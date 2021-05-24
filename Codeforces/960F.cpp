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

map<int, int> mp[MN];

int get(int u, int w) {
    auto it = mp[u].lower_bound(w);
    if (it == mp[u].begin()) return 0;
    it--;
    return it->second;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        int val = get(a, c);
        if (get(b, c) > val + 1) continue;
        mp[b][c] = max(mp[b][c], val + 1);
        auto it = mp[b].upper_bound(c);
        while (it != mp[b].end()) {
            if (it->second > mp[b][c]) break;
            it = mp[b].erase(it);
        }
        ans = max(ans, mp[b][c]);
    }
    cout << ans << '\n';
    return 0;
}
