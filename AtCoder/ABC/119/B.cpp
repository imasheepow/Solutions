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
const double RATE = 380000.0;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N; cin >> N;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        double x; string u; cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += x * RATE;
    }
    cout << fixed << setprecision(5) << ans << '\n';
    return 0;
}
