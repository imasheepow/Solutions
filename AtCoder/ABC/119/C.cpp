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
int N, A, B, C, l[10];

int go(int cur, int a, int b, int c) {
    if (cur == N) {
        if (min({a, b, c}) > 0) return abs(A - a) + abs(B - b) + abs(C - c) - 30;
        else return 1e9;
    }
    int ret = 1e9;
    ret = min(ret, go(cur + 1, a, b, c));
    ret = min(ret, go(cur + 1, a + l[cur], b, c) + 10);
    ret = min(ret, go(cur + 1, a, b + l[cur], c) + 10);
    ret = min(ret, go(cur + 1, a, b, c + l[cur]) + 10);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) cin >> l[i];
    cout << go(0, 0, 0, 0) << '\n';
    return 0;
}
