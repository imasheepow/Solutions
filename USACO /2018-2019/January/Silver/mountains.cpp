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

int N;
struct Point {
    int x, y;
    bool operator<(Point &o) const {
        if (x == o.x) return y > o.y;
        return x < o.x;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("mountains");
    cin >> N;
    vector<Point> pt;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pt.pb({x - y, x + y});
    }
    sort(all(pt));
    int ans = 0, mx = 0;
    for (auto [x, y] : pt) {
        if (mx < y) mx = y, ans++;
    }
    cout << ans << '\n';
    return 0;
}
