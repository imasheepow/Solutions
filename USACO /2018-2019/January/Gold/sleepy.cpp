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

int N, a[MN];
int b[MN];
void upd(int i) {
    for (; i < MN; i += i & -i) b[i]++;
}
int get(int i) {
    int r = 0;
    for (; i; i -= i & -i) r += b[i];
    return r;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("sleepy");
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    a[N + 1] = 1e9;
    // get maximal sorted suffix, then insert into it
    int notDone = N;
    for (int i = N; i >= 1; i--) {
        if (a[i] < a[i + 1]) upd(a[i]), notDone--;
        else break;
    }
    vi ans;
    for (int i = 1; i <= notDone; i++) {
        ans.pb(notDone - i + get(a[i]));
        upd(a[i]);
    }
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++)
        cout << ans[i] << " \n"[i == sz(ans) - 1];
    return 0;
}
