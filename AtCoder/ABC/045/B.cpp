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
string s[3];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s[0] >> s[1] >> s[2];
    int cur = 0;
    while (true) {
        if (s[cur].empty()) break;
        int nxt = s[cur][0] - 'a';
        s[cur].erase(s[cur].begin());
        cur = nxt;
    }
    cout << char(cur + 'A') << '\n';
    return 0;
}
