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
const int N = 1e5 + 7;
int n, h[N], lim, ans[N];
pii st[N][20];
int Log2[N];
pii RMQ(int l, int r) {
    int lv = Log2[r - l + 1];
    pii ansl = st[l][lv];
    pii ansr = st[r - (1 << lv) + 1][lv];
    return {max(ansl.fi, ansr.fi), min(ansl.se, ansr.se)};
}
void ini() {
    rep(i, 0, n) st[i][0] = mp(h[i], h[i]);
    rep(j, 1, 20) rep(i, 0, n) {
        if (i + (1 << j) > n) break;
        st[i][j].fi = max(st[i][j - 1].fi, st[i + (1 << (j - 1))][j - 1].fi);
        st[i][j].se = min(st[i][j - 1].se, st[i + (1 << (j - 1))][j - 1].se);
    }
}
void solve() {
    rep(i, 0, n) scanf("%d", h + i);
    ini();
    rep(i, 0, n) {
        for (int l = 0, r = i, mid = l + r >> 1; l <= r; mid = l + r >> 1) {
            pii tmp = RMQ(mid, i);
            if (tmp.fi - tmp.se <= lim) r = (ans[i] = mid) - 1;
                else l = mid + 1;
        }
    }
    int mx = -1;
    rep(i, 0, n) mx = max(mx, i - ans[i] + 1);
    vector<pii> v;
    rep(i, 0, n) if (i - ans[i] + 1 == mx) v.pb({ans[i], i});
    printf("%d %d\n", mx, sz(v));
    rep(i, 0, sz(v)) printf("%d %d\n", v[i].fi +1, v[i].se + 1);
}
int main() {
    //freopen("xx.in", "r", stdin);
    Log2[1] = 0; rep(i, 2, N) Log2[i] = Log2[i >> 1] + 1;
    while (~scanf("%d%d", &n, &lim)) solve();

    return 0;
}
