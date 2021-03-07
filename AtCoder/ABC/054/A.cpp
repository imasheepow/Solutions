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
    int A, B; cin >> A >> B;
    if (A == 1) A = 14;
    if (B == 1) B = 14;
    if (A > B) cout << "Alice\n";
    else if (B > A) cout << "Bob\n";
    else cout << "Draw\n";
    return 0;
}
