#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 5e6 + 5;
int M, N, K;
int row[MN], col[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'R') row[x] ^= 1;
        else col[x] ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ((row[i] ^ col[j]) == 1) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
