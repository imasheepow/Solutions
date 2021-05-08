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
bool ok[MN];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll prod = 1;
    int num = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            ok[i] = 1;
            prod = (prod * i) % n;
            num++;
        }
    }
    if (prod != 1) ok[prod] = 0, num--;
    cout << num << '\n';
    for (int i = 1; i < n; i++) {
        if (ok[i]) {
            cout << i << " ";
        }
    }
    return 0;
}