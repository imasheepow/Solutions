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
string s; ll ans;

void go(int cur, ll sum, string num) {
    if (cur == sz(s) - 1) {
        sum += stoll(num);
        ans += sum;
        return;
    }
    go(cur + 1, sum, num + s[cur + 1]);
    go(cur + 1, sum + stoi(num), string(1, s[cur + 1]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    go(0, 0, string(1, s[0]));
    cout << ans << '\n';
    return 0;
}
