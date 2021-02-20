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
int A, B, T;
int a[MN], b[MN];
pii t[MN];
int lim[MN];

bool chk(int x) {
    priority_queue<int> q;
    int pos = 0;
    for (int i = 0; i < A; i++) {
        while (pos < lim[i]) q.push(t[pos++].second);
        for (int j = 0; !q.empty() && j < x; j++) q.pop();
    }
    while (pos < T) q.push(t[pos++].second);
    for (int i = 0; i < B; i++) {
        if (q.empty()) return true;
        if (q.top() >= b[i]) return false;
        for (int j = 0; !q.empty() && j < x; j++) q.pop();
    }
    return q.empty();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> T;
    for (int i = 0; i < A; i++) cin >> a[i];
    for (int i = 0; i < B; i++) cin >> b[i];
    for (int i = 0; i < T; i++) cin >> t[i].first >> t[i].second;
    sort(a, a + A);
    sort(b, b + B, greater<>());
    sort(t, t + T);
    for (int i = 0; i < A; i++) {
        lim[i] = lower_bound(t, t + T, pii(a[i], 0)) - t;
    }
    int l = 1, r = T + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(m)) r = m;
        else l = m + 1;
    }
    if (l == T + 1) l = -1;
    cout << l << '\n';
    return 0;
}
