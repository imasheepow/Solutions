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
int N, M, cnt[31];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            cnt[a]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        if (cnt[i] == N) ans++;
    }
    cout << ans << '\n';
    return 0;
}
