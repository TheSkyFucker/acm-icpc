#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define dd(x) cout << #x << " => " << x << " "
#define de(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
int n, r, a[N];
struct Node {
	int ls, rs, mi;
	Node() { ls = rs = 0; }
	void ini(int mi) { this->mi = mi; }
	void upd(const Node &ls, const Node &rs) {
		mi = min(ls.mi, rs.mi);
	}
};
int rt[N];
struct Tree {
	static const int N = ::N << 6;
	Node nd[N]; int _;
	void ini() { nd[_ = 0].ini(INF); }
	void upd(int o) { nd[o].upd(nd[nd[o].ls], nd[nd[o].rs]); }
	void bud(int &o, int l, int r, int qx, int qv) {
		o = ++_; nd[o] = Node();
		if (l == r) { nd[o].ini(qv); return; }
		int mid = l + r >> 1;
		if (qx <= mid) bud(nd[o].ls, l, mid, qx, qv);
		else bud(nd[o].rs, mid + 1, r, qx, qv);
		upd(o);
	}
	int meg(int a, int b) {
		if (!a || !b) return !a ? b : a;
		int c = ++_; nd[c] = Node();
		nd[c].ls = meg(nd[a].ls, nd[b].ls);
		nd[c].rs = meg(nd[a].rs, nd[b].rs);
		if (!nd[c].ls && !nd[c].rs) nd[c].ini(min(nd[a].mi, nd[b].mi));
		else upd(c);
		return c;
	}
	int qry(int o, int l, int r, int ql, int qr) {
		if (!o) return INF;
		if (ql <= l && qr >= r) return nd[o].mi;
		int mid = l + r >> 1, ret = INF;
		if (ql <= mid) ret = min(ret, qry(nd[o].ls, l, mid, ql, qr));
		if (qr >  mid) ret = min(ret, qry(nd[o].rs, mid + 1, r, ql, qr));
		return ret;
	}
}	tree;

int dep[N];
vi g[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	tree.bud(rt[u], 1, n, dep[u], a[u]);
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		rt[u] = tree.meg(rt[u], rt[v]);
	}
}

void solve() {
	tree.ini();
	rep(i, 1, n + 1) scanf("%d", &a[i]);
	rep(i, 1, n + 1) g[i].clear();
	rep(i, 1, n) {
		int a, b; scanf("%d%d", &a ,&b);
		g[a].pb(b); g[b].pb(a);
	}
	dfs(r, 0);
	int qn; scanf("%d", &qn); int last = 0;
	rep(i, 0, qn) {
		int p, q; scanf("%d%d", &p, &q);
		int x = ((p + last) % n) + 1;
		int y = ((q + last) % n);
		printf("%d\n", last = tree.qry(rt[x], 1, n, dep[x], dep[x] + y));
	}
}
	
int main() {
	while (~scanf("%d%d", &n, &r)) solve();
	return 0;

}
