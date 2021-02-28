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
int cnt[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            cnt[j]++;
        }
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
    return 0;
}
