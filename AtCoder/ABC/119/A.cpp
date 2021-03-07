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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    int month = stoi(s.substr(5, 2));
    cout << (month > 4 ? "TBD" : "Heisei") << '\n';
    return 0;
}
