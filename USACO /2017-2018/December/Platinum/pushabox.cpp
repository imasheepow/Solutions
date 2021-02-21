#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1505, MM = MN * MN;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, Q;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char grid[MN][MN];

bool bad(int i, int j) {
    return i < 1 || i > N || j < 1 || j > M || grid[i][j] == '#';
}

int nd(int i, int j) {
    return (i - 1) * M + j;
}

int tin[MN][MN], low[MN][MN], tt, cnt;
stack<pair<pii, pii>> s;
set<int> comp[MM];

void process(int x, int y, int nx, int ny) {
    if (s.empty()) return;
    cnt++;
    while (!s.empty()) {
        auto cur = s.top(); s.pop();
        int a = cur.first.first, b = cur.first.second;
        int c = cur.second.first, d = cur.second.second;
        comp[nd(a, b)].insert(cnt);
        comp[nd(c, d)].insert(cnt);
        if (cur == pair<pii, pii>(pii(x, y), pii(nx, ny))) break;
    }
}

void tar(int x, int y, int px, int py) {
    tin[x][y] = low[x][y] = ++tt;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (bad(nx, ny)) continue;
        if (nx == px && ny == py) continue;
        if (!tin[nx][ny]) {
            s.push({{x, y}, {nx, ny}});
            tar(nx, ny, x, y);
            low[x][y] = min(low[x][y], low[nx][ny]);
            if (low[nx][ny] >= tin[x][y]) {
                process(x, y, nx, ny);
            }
        } else if (tin[nx][ny] < tin[x][y]) {
            s.push({{x, y}, {nx, ny}});
            low[x][y] = min(low[x][y], tin[nx][ny]);
        }
    }
}

// each cell is part of at most 4 bccs
bool same(int i, int j) {
    for (int c : comp[i])
        if (comp[j].count(c)) return true;
    return false;
}

bool start[MN][MN];
void go(int i, int j) {
    if (start[i][j]) return;
    start[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (bad(ni, nj) || grid[ni][nj] == 'B') continue;
        go(ni, nj);
    }
}
bool ok[MN][MN][4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIO("pushabox");
    cin >> N >> M >> Q;
    int sx = 0, sy = 0, bx = 0, by = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') sx = i, sy = j;
            if (grid[i][j] == 'B') bx = i, by = j;
        }
    }
    tar(sx, sy, -1, -1), process(-1, -1, -1, -1);
    go(sx, sy);
    queue<pair<pii, int>> q;
    for (int k = 0; k < 4; k++) {
        int ax = bx + dx[k], ay = by + dy[k];
        if (bad(ax, ay)) continue;
        if (start[ax][ay]) {
            q.push({{bx, by}, k});
            ok[bx][by][k] = true;
        }
    }
    while (!q.empty()) {
        pair<pii, int> cur = q.front(); q.pop();
        int i = cur.first.first, j = cur.first.second; int d = cur.second;
        int x = i + dx[d], y = j + dy[d];
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (bad(nx, ny)) continue;
            if (nx == x && ny == y) continue;
            if (same(nd(x, y), nd(nx, ny)) && !ok[i][j][k]) {
                ok[i][j][k] = true;
                q.push({{i, j}, k});
            }
            if (k == 3 - d && !ok[nx][ny][d]) {
                ok[nx][ny][d] = true;
                q.push({{nx, ny}, d});
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int ex, ey; cin >> ex >> ey;
        bool ans = false;
        if (ex == bx && ey == by) ans = true;
        for (int k = 0; k < 4; k++) ans |= ok[ex][ey][k];
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
