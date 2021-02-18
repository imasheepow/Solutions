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

int N, M, c[MN];
/*
 * given a sorted sequence a1, a2,..., an, and a sequence b, find a subsequence of b such that
 * every element can be covered by an element of a (bi <= ai)
 * since a is sorted, we can just choose starting from the largest element greedily. 
 */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    vector<pii> a;
    for (int i = 0; i < N; i++) {
        int s, v; cin >> s >> v;
        a.eb(v, s);
    }
    for (int i = 0; i < M; i++) cin >> c[i];
    sort(all(a), greater<>());
    sort(c, c + M, greater<>());
    int ans = 0;
    for (int i = 0; i < N && ans < M; i++) {
        if (c[ans] >= a[i].second) ans++;
    }
    cout << ans << '\n';
    return 0;
}
