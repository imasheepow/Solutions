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
int n, k;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    string s;
    for (char i = 'a'; i < 'a' + k; i++) {
        s.pb(i);
        for (char j = i + 1; j < 'a' + k; j++) s.pb(i), s.pb(j);
    }
    for (int i = 0; i < n; i++) cout << s[i % sz(s)];
    return 0;
}
