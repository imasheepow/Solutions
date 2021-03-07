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
int N, p[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> p[i];
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (p[i] == i) {
            swap(p[i], p[i + 1]);
            ans++;
        }
    }
    if (p[N] == N) ans++;
    cout << ans << '\n';
    return 0;
}
