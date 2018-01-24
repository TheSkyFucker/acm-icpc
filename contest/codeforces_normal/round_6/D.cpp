#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e2 + 7;
int n, a, b, h[N];
void gao(int p, int v = -1) {
    h[p] += a * v;
    h[p - 1] += b * v;
    h[p + 1] += b * v;
}
int ans[N], mi;
int tmp[N];
void dfs(int s, int ned = 0) {
    if (ned >= mi) return;
    if (s >= n) {
        mi = ned;
        rep(i, 2, n) ans[i] = tmp[i];
        return;
    }
    int mx = 0;
    for (tmp[s] = 0; ; tmp[s]++, mx++) {
        if (h[s - 1] <= 0 && (s < n - 1 || h[s] <= 0)) dfs(s + 1, ned + mx);
        if (h[s - 1] <= 0 && h[s] <= 0) break;
        gao(s);
    }
    rep(i, 0, mx) gao(s, 1);
}

void solve() {
    rep(i, 1, n + 1) scanf("%d", &h[i]);
    rep(i, 1, n + 1) h[i]++;
    int ini1 = 0, inin = 0;
    if (h[1] > 0) { ini1 = (h[1] - 1) / b + 1; rep(i, 0, ini1) gao(2); }
    if (h[n] > 0) { inin = (h[n] - 1) / b + 1; rep(i, 0, inin) gao(n - 1); }
    fill_n(ans + 1, n, 0);
    mi = 0x3f3f3f3f;
    dfs(2);
    ans[2] += ini1;
    ans[n - 1] += inin;
    int tot = 0;
    rep(i, 1, n + 1) tot += ans[i];
    printf("%d\n", tot);
    rep(i, 1, n + 1) rep(j, 0, ans[i]) printf("%d ", i);
    puts("");
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d%d%d", &n, &a, &b))solve();

    return 0;
}