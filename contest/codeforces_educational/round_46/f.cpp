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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 5e5 + 7;
int a[N], n, q, ans[N], cur[N];
vi g[N], chg[N];
vector<pii> qry[N];
struct Tree {
	static const int N = ::N << 2;
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
	pii a[N];
	void chg(int o, int l, int r, int ql, int qr, int id) {
		if (ql <= l && r <= qr) { a[o] = max(a[o], mp(ql, id)); return; }
		int mid = l + r >> 1;
		if (ql <= mid) chg(ls, l, mid, ql, qr, id);
		if (qr >  mid) chg(rs, mid + 1, r, ql, qr, id);
	}
	pii qry(int o, int l, int r, int qx) {
		if (l == r) return a[o];
		int mid = l + r >> 1;
		return max(a[o], qx <= mid ? qry(ls, l, mid, qx) : qry(rs, mid + 1, r, qx));
	}
}	tree;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> n;
  rep(i, 1, N) g[i].pb(0);
  rep(i, 1, n + 1) cin >> a[i], g[a[i]].pb(i);
  rep(i, 1, N) g[i].pb(n + 1);
	rep(i, 1, N) {
		cur[i] = 1;
		rep(j, 0, sz(g[i]) - 2)
			chg[g[i][j] + 1].pb(i);
	}
  cin >> q;
  rep(i, 0, q) { 
  	int l, r; cin >> l >> r;
  	qry[l].pb({r, i});
	}
	rep(i, 1, n + 1) {
		for (auto e : chg[i]) tree.chg(1, 1, n, g[e][cur[e]], g[e][cur[e] + 1] - 1, e), cur[e]++;
		for (auto e : qry[i]) {
			auto tmp = tree.qry(1, 1, n, e.fi);
			if (tmp.fi >= i) ans[e.se] = tmp.se;
		}
	}
	rep(i, 0, q) cout << ans[i] << endl;
	return 0;
}
