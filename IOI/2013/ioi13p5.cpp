#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e6 + 5;
int A, B, T;
int a[MN], b[MN];
pii t[MN];
int lim[MN];

/* 
 * after sorting the toys in increasing weight
 * each weak robot should have a prefix of toys that it can carry
 * considering the weak robots from weakest to strongest, we can maintain the largest sizes
 * take the largest sizes to give less work for the small robots
 * if the small robots cannot carry the remaining then it is not possible
 */

bool chk(int x) {
    priority_queue<int> q;
    int pos = 0;
    for (int i = 0; i < A; i++) {
        while (pos < lim[i]) q.push(t[pos++].second);
        for (int j = 0; !q.empty() && j < x; j++) q.pop();
    }
    while (pos < T) q.push(t[pos++].second);
    for (int i = 0; i < B; i++) {
        if (q.empty()) return true;
        if (q.top() >= b[i]) return false;
        for (int j = 0; !q.empty() && j < x; j++) q.pop();
    }
    return q.empty();
}

int putaway(int _A, int _B, int _T, int X[], int Y[], int W[], int S[]) {
    A = _A, B = _B, T = _T;
    for (int i = 0; i < A; i++) a[i] = X[i];
    for (int i = 0; i < B; i++) b[i] = Y[i];
    for (int i = 0; i < T; i++) t[i] = {W[i], S[i]};
    sort(a, a + A);
    sort(b, b + B, greater<>());
    sort(t, t + T);
    for (int i = 0; i < A; i++) {
        lim[i] = lower_bound(t, t + T, pii(a[i], 0)) - t;
    }
    int l = 1, r = T + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(m)) r = m;
        else l = m + 1;
    }
    if (l == T + 1) l = -1;
    return l;
}
