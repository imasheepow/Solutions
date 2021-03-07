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
int N, cnt[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a) cnt[a - 1]++;
        cnt[a]++, cnt[a + 1]++;
    }
    cout << *max_element(cnt, cnt + MN) << '\n';
    return 0;
}
