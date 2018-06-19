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
const int N = 1e5 + 7;
struct Trie {
	static const int N = ::N * 200, M = 20;
	int son[N][2], sz[N], _;
	void ini() { _ = 0; }
	int ne() {
		int ret = _++;
		fill_n(son[ret], 2, -1); sz[ret] = 0;
		return ret;
	}
	void insert(int u, const int a) {
		sz[u]++;
		per(i, 0, M) {
			int &v = son[u][a >> i & 1];
			if (!~v) v = ne();
			u = v;
			sz[u]++;
		}
	}
	void comb(int a, int b) { // a into b
		sz[b] += sz[a];
		rep(i, 0, 2) if (~son[a][i]) {
			int &as = son[a][i];
			int &bs = son[b][i];
			if (!~bs) bs = ne();
			comb(as, bs);
		}
	}
	int qry(int u, const int a, const int limit) {
		int ret = 0;
		per(i, 0, M) {
			int ai = a >> i & 1;
			int li = limit >> i & 1;
			rep(j, 0, 2) if (~son[u][j]) {
				if ((j ^ ai) < li) continue;
				if ((j ^ ai) > li) ret += sz[son[u][j]];
			}
			if (!~son[u][ai ^ li]) break;
			u = son[u][ai ^ li];
		}
		return ret;
	}
}	tree;

int n, a[N];
int ls[N], rs[N], root, rt[N];
int dfn[N], in[N], ot[N], _dfn, sz[N]; // [in[u], ot[u])
ll _ans;
void dfs(int u) {
	sz[u] = 1;
	dfn[_dfn] = u;
	in[u] = _dfn++;
	if (~ls[u]) dfs(ls[u]), sz[u] += sz[ls[u]];
	if (~rs[u]) dfs(rs[u]), sz[u] += sz[rs[u]];
	ot[u] = _dfn;
}
void gao(int u) {
	if (~ls[u]) gao(ls[u]);
	if (~rs[u]) gao(rs[u]);
	if (!~ls[u] && !~rs[u]) {
		rt[u] = tree.ne();
		tree.insert(rt[u], a[u]);
		return ;
	}
	ll _tmp = 0;
	int szl = ~ls[u] ? sz[ls[u]] : 0;
	int szr = ~rs[u] ? sz[rs[u]] : 0;
	if (szl < szr) {
		tree.insert(rt[rs[u]], a[u]);
		if (szl) {
			rep(i, in[ls[u]], ot[ls[u]])
				_tmp += tree.qry(rt[rs[u]], a[dfn[i]], a[u]) * 1ll * a[u];
		}
		_tmp += tree.qry(rt[rs[u]], a[u], a[u]) * 1ll * a[u];
	}
	else {
		tree.insert(rt[ls[u]], a[u]);
		if (szr) {
			rep(i, in[rs[u]], ot[rs[u]])
				_tmp += tree.qry(rt[ls[u]], a[dfn[i]], a[u]) * 1ll * a[u];
		}
		_tmp += tree.qry(rt[ls[u]], a[u], a[u]) * 1ll * a[u];
	}
	_ans += _tmp;
	//dd(u); de(_tmp);
	if (!~ls[u]) rt[u] = rt[rs[u]];
	else if (!~rs[u]) rt[u] = rt[ls[u]];
	else {
		if (sz[ls[u]] < sz[rs[u]]) {
			tree.comb(rt[ls[u]], rt[rs[u]]);
			rt[u] = rt[rs[u]];
		}
		else {
			tree.comb(rt[rs[u]], rt[ls[u]]);
			rt[u] = rt[ls[u]];
		}
	}
}

void dk() {
	vi stk;
	fill_n(ls, n, -1);
	fill_n(rs, n, -1);
	rep(i, 0, n) {
		int pre = -1;
		while (!stk.empty() && a[stk.back()] < a[i]) {
			pre = stk.back(); stk.pop_back();
		}
		ls[i] = pre;
		if (!stk.empty()) rs[stk.back()] = i;
		stk.pb(i);
	}
	root = stk[0];
}
		
void solve() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	dk();
	_dfn = 0; dfs(root);
	tree.ini();
	_ans = 0; gao(root);
	cout << _ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int tcas; cin >> tcas;
  rep(cas, 0, tcas) solve();
	return 0;
}
