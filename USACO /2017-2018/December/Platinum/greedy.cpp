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

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, a[MN], ps[MN];
// if there are k people before me that all cut into ranks <= k, then i and all people behind me will never get presents
bool chk(int x) {
    memset(ps, 0, sizeof(ps));
    for (int i = 1; i <= x; i++) ps[a[i]]++;
    for (int i = 1; i <= N; i++) {
        ps[i] += ps[i - 1];
        if (ps[i] >= i) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("greedy");
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] = N - a[i];
    }
    int l = 0, r = N;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(m)) l = m + 1;
        else r = m;
    }
    cout << N - l << '\n';
    return 0;
}
