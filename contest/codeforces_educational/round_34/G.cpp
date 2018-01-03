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

//------
const int N = 2e5 + 7;
int n, m, q;
ll a[N], b[N], c[N];

struct Nd {
    ll mi, tag;
    Nd() {} Nd(ll mi, ll tag) : mi(mi), tag(tag) {}
    void add(ll v) { mi += v, tag += v; }
    void upd(const Nd &ls, const Nd &rs) {
        mi = min(ls.mi, rs.mi); tag = 0;
    }
};
struct Tree {
    static const int N = ::N << 2;
    Nd nd[N];
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
    void upd(int o) { nd[o].upd(nd[ls], nd[rs]); }
    void dwn(int o) {
        nd[ls].add(nd[o].tag);
        nd[rs].add(nd[o].tag);
        nd[o].tag = 0;
    }
    void bud(int o, int l, int r, ll a[]) {
        if (l == r) { nd[o] = Nd(a[l], 0); return; }
        int mid = l + r >> 1;
        bud(ls, l, mid, a);
        bud(rs, mid + 1, r, a);
        upd(o);
    }
    void add(int o, int l, int r, int ql, int qr, ll qv) {
        if (ql <= l && qr >= r) { nd[o].add(qv); return; }
        dwn(o);
        int mid = l + r >> 1;
        if (ql <= mid) add(ls, l, mid, ql, qr, qv);
        if (qr >  mid) add(rs, mid + 1, r, ql, qr, qv);
        upd(o);
    }
}    tree;

vector<pii> g[N];
void solve() {
    rep(i, 1, n) scanf("%lld%lld", a + i, b + i); a[n] = 0;
    rep(i, 1, n + 1) g[i].clear();
    rep(i, 0, m) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g[a].pb({b, c});
    }
    tree.bud(1, 0, n - 1, b);
    rep(i, 1, n + 1) {
        for (auto e : g[i]) tree.add(1, 0, n - 1, 0, e.fi - 1, e.se);
        c[i] = a[i] + tree.nd[1].mi;
    }
    tree.bud(1, 1, n, c);
    printf("%lld\n", tree.nd[1].mi);
    rep(i, 1, q + 1) {
        int qx; ll qv; scanf("%d%lld", &qx, &qv);
        tree.add(1, 1, n, qx, qx, qv - a[qx]); a[qx] = qv;
        printf("%lld\n", tree.nd[1].mi);
    }
}
int main() {
    while (~scanf("%d%d%d", &n, &m, &q)) solve();
    return 0;
}