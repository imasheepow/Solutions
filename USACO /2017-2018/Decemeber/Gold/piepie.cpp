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

int N, D, a[2 * MN], b[2 * MN], dis[2 * MN];

struct cmp {
    bool operator() (int i, int j) const {
        return a[i] < a[j];
    }
};

struct cmp2 {
    bool operator() (int i, int j) const {
        return b[i] < b[j];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("piepie");
    cin >> N >> D;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> a[i] >> b[i];
        a[i] = -a[i], b[i] = -b[i];
        dis[i] = -1;
    }
    queue<int> q;
    multiset<int, cmp> sa;
    multiset<int, cmp2> sb;
    for (int i = 1; i <= 2 * N; i++) {
        if (i <= N) {
            if (!b[i]) dis[i] = 1, q.push(i);
            else sb.insert(i);
        } else {
            if (!a[i]) dis[i] = 1, q.push(i);
            else sa.insert(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u <= N) {
            while (true) {
                auto it = sa.lower_bound(u);
                if (it == sa.end() || a[*it] > a[u] + D) break;
                dis[*it] = dis[u] + 1;
                q.push(*it);
                sa.erase(it);
            }
        } else {
            while (true) {
                auto it = sb.lower_bound(u);
                if (it == sb.end() || b[*it] > b[u] + D) break;
                dis[*it] = dis[u] + 1;
                q.push(*it);
                sb.erase(it);
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << dis[i] << '\n';
    return 0;
}
