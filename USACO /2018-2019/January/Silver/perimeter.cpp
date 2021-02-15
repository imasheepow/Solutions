#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e3 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N;
char grid[MN][MN];
bool vis[MN][MN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int area, per;

bool empty(int i, int j) {
    return i < 1 || i > N || j < 1 || j > N || grid[i][j] == '.';
}

void dfs(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;
    area++;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (empty(ni, nj)) per++;
        else dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("perimeter");
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    int mx = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!vis[i][j] && grid[i][j] == '#') {
                area = per = 0;
                dfs(i, j);
                if (mx < area) mx = area, ans = per;
                else if (mx == area) ans = min(ans, per);
            }
        }
    }
    cout << mx << " " << ans << '\n';
    return 0;
}
