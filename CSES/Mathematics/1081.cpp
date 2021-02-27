#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5, MM = 1e6 + 5;
int N, cnt[MM];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = 1e6; i >= 1; i--) {
        int num = 0;
        for (int j = i; j <= 1e6; j += i) {
            num += cnt[j];
            if (num >= 2) {
                cout << i << '\n'; return 0;
            }
        }
    }
    return 0;
}
