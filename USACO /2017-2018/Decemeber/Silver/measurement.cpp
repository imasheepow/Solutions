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

int N, G;
struct Event {
    int d, c, x;
    bool operator <(Event &o) const {
        return d < o.d;
    }
};
vector<Event> ev;
map<int, int> a;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("measurement");
    cin >> N >> G;
    multiset<int, greater<int>> s;
    for (int i = 0; i < N; i++) {
        int d, c, x; char op;
        cin >> d >> c >> op >> x;
        if (op == '-') x = -x;
        ev.pb({d, c, x});
        s.insert(0);
    }
    sort(all(ev));
    int ans = 0;
    for (auto [d, c, x] : ev) {
        int nxt = a[c] + x;
        int pmx = *s.begin();
        int pnum = s.count(pmx);
        s.erase(s.find(a[c]));
        s.insert(nxt);
        int nmx = *s.begin();
        int nnum = s.count(nmx);
        if (nxt == nmx && a[c] != pmx) ans++;
        else if (nxt != nmx && a[c] == pmx) ans++;
        else if (nxt == nmx && a[c] == pmx && (pnum > 1 || nnum > 1)) ans++;
        a[c] = nxt;
    }
    cout << ans << '\n';
    return 0;
}
