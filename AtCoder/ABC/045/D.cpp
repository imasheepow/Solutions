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
int H, W, N;
map<pii, int> mp;
int cnt[10];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        for (int x = a - 2; x <= a; x++) {
            for (int y = b - 2; y <= b; y++) {
                if (x >= 1 && y >= 1 && x + 2 <= H && y + 2 <= W) {
                    mp[{x, y}]++;
                }
            }
        }
    }
    for (auto [p, q] : mp) {
        cnt[q]++;
    }
    cout << 1LL * (H - 2) * (W - 2) - sz(mp) << '\n';
    for (int i = 1; i <= 9; i++) cout << cnt[i] << '\n';
    return 0;
}
