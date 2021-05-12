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

int N, Q;
set<int> xs;
multiset<int, greater<>> lens;

void add(int x) {
    xs.insert(x);
    auto nxt = xs.find(x), pre = nxt;
    bool hp = false, hn = false;
    if (pre != xs.begin()) --pre, lens.insert(x - *pre), hp = true;
    ++nxt;
    if (nxt != xs.end()) lens.insert(*nxt - x), hn = true;
    if (hp && hn) lens.erase(lens.find(*nxt - *pre));
}

void rem(int x) {
    auto nxt = xs.find(x), pre = nxt;
    bool hp = false, hn = false;
    if (pre != xs.begin()) --pre, lens.erase(lens.find(x - *pre)), hp = true;
    ++nxt;
    if (nxt != xs.end()) lens.erase(lens.find(*nxt - x)), hn = true;
    if (hp && hn) lens.insert(*nxt - *pre);
    xs.erase(x);
}

int qry() {
    if (xs.size() <= 2) return 0;
    int ret = *(--xs.end()) - *xs.begin() - *lens.begin();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        add(x);
    }
    cout << qry() << '\n';
    for (int i = 0; i < Q; i++) {
        int t, x; cin >> t >> x;
        if (t == 0) rem(x);
        else add(x);
        cout << qry() << '\n';
    }
    return 0;
}
