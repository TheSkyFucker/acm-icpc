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
int add(int a, int b, int MOD) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b, int MOD) { return 1ll * a * b % MOD; }
int qpow(int a, int b, int MOD) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a, MOD);
		a = mul(a, a, MOD);
	}
	return r;
}

const int N = 1e5 + 7;
int n, m, seed, vmax;
int a[N];

int rnd() {
	int ret = seed;
	seed = (7ll * seed + 13) % 1000000007;
	return ret;
}

vector<pair<ll, int> > v;
struct Nd {
	ll v, tval;
	char ttp;
	void chg(ll nv) {
		v = tval = nv;
		ttp = 'c';
	}
	void add(ll mv) {
		if (~v) v += mv;
		if (ttp != '-') tval += mv;
		else ttp = 'a', tval = mv;
	}
	void upd(const Nd &ls, const Nd &rs) {
		ttp = '-';
		v = ls.v == rs.v ? ls.v : -1;
	}
};
struct Tree {
	static const int N = ::N << 2;
	Nd nd[N];
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
	void upd(int o) { nd[o].upd(nd[ls], nd[rs]); }
	void dwn(int o) {
		if (nd[o].ttp == '-') return;
		if (nd[o].ttp == 'a') {
			nd[ls].add(nd[o].tval);
			nd[rs].add(nd[o].tval);
		}
		else {
			nd[ls].chg(nd[o].tval);
			nd[rs].chg(nd[o].tval);
		}
		nd[o].ttp = '-';
	}
	void bud(int o, int l, int r) {
		if (l == r) { nd[o].v = a[l]; nd[o].ttp = '-';  return; }
		int mid = l + r >> 1;
		bud(ls, l, mid);
		bud(rs, mid + 1, r);
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
	void chg(int o, int l, int r, int ql, int qr, ll qv) {
		if (ql <= l && qr >= r) { nd[o].chg(qv); return; }
		dwn(o);
		int mid = l + r >> 1;
		if (ql <= mid) chg(ls, l, mid, ql, qr, qv);
		if (qr >  mid) chg(rs, mid + 1, r, ql, qr, qv);
		upd(o);
	}
	void qry(int o, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r && ~nd[o].v) {
			v.pb({nd[o].v, r - l + 1});
			return;
		}
		dwn(o);
		int mid = l + r >> 1;
		if (ql <= mid) qry(ls, l, mid, ql, qr);
		if (qr >  mid) qry(rs, mid + 1, r, ql, qr);
		upd(o);
	}
}	tree;


void solve() {
	rep(i, 1, n + 1) a[i] = rnd() % vmax + 1;
	//rep(i, 1, n + 1) de(a[i]);
	tree.bud(1, 1, n);
	rep(i, 1, m + 1) {
		int op = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		if (l > r) swap(l, r);
		int x = op == 3
			? (rnd() % (r - l +1)) + 1
			: (rnd() % vmax) + 1;
		int y; if (op == 4) y = (rnd() % vmax) + 1;
		if (op == 1) {
			//printf("%d %d %d %d\n", op, l, r, x);
			tree.add(1, 1, n, l, r, x);
			//de(tree.nd[12].v);
			//de(tree.nd[12].tval);
		}
		else if (op == 2) {
			//printf("%d %d %d %d\n", op, l, r, x);
			tree.chg(1, 1, n, l, r, x);
		}
		else if (op == 3) {
			//printf("%d %d %d %d\n", op, l, r, x);
			v.clear();
			tree.qry(1, 1, n, l, r);
			sort(all(v));
			rep(i, 0, sz(v)) {
				if (x <= v[i].se) { printf("%lld\n", v[i].fi); break; }
				else x -= v[i].se;
			}
		}
		else {
			//printf("%d %d %d %d %d\n", op, l, r, x, y);
			v.clear();
			tree.qry(1, 1, n, l, r);
			int ans = 0;
			//rep(i, 0, sz(v)) { dd(v[i].fi); de(v[i].se); }
			for (int l = 0, r; l < sz(v); l = r) {
				int cnt = 0;
				r = l; while (r < sz(v) && v[r].fi == v[l].fi) cnt += v[r++].se;
				ans = add(ans, mul(qpow(v[l].fi % y, x, y), cnt, y), y);
			}
			printf("%d\n", ans);
		}
	}
}
		

int main() {
	while (~scanf("%d%d%d%d", &n, &m, &seed, &vmax)) solve();

	return 0;
}
