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
const int N = 1e5 + 7;

int n, m, a[N];
struct Nd {
	db v, tadd, tmul; int sz;
	Nd() {} Nd(db v, db tmul, db tadd) : v(v), tmul(tmul), tadd(tadd) {}
	void chg(db _tmul, db _tadd) {
		tmul = tmul * _tmul;
		tadd = tadd * _tmul + _tadd;
		v = v * _tmul + _tadd * sz;
	}
	void upd(const Nd &ls, const Nd &rs) { v = ls.v + rs.v; }
};
struct Tree {
	static const int N = ::N << 2;
	Nd nd[N];
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
	void upd(int o) { nd[o].upd(nd[ls], nd[rs]); }
	void dwn(int o) {
		nd[ls].chg(nd[o].tmul, nd[o].tadd);
		nd[rs].chg(nd[o].tmul, nd[o].tadd);
		nd[o].tmul = 1.0; nd[o].tadd = 0.;
	}
	void bud(int o, int l, int r) {
		nd[o] = Nd(0., 1., 0.);
		nd[o].sz = r - l + 1;
		if (l == r) { nd[o].v = a[l]; return; }
		int mid = l + r >> 1;
		bud(ls, l, mid);
		bud(rs, mid + 1, r);
		upd(o);
	}
	void chg(int o, int l, int r, int ql, int qr, db tmul, db tadd) {
		if (ql <= l && qr >= r) { nd[o].chg(tmul, tadd); return; }
		dwn(o);
		int mid = l + r >> 1;
		if (ql <= mid) chg(ls, l, mid, ql, qr, tmul, tadd);
		if (qr >  mid) chg(rs, mid + 1, r, ql, qr, tmul, tadd);
		upd(o);
	}
	db qry(int o, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r) return nd[o].v;
		dwn(o);
		int mid = l + r >> 1;
		db ret = 0;
		if (ql <= mid) ret += qry(ls, l, mid, ql, qr);
		if (qr >  mid) ret += qry(rs, mid + 1, r, ql, qr);
		return ret;
	}
}	tree;
	
void solve() {
	rep(i,1, n + 1) scanf("%d", a + i);
	tree.bud(1, 1, n);
	rep(_m, 0, m) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int l1, r1, l2, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
			db sum1 = tree.qry(1, 1, n, l1, r1);
			db sum2 = tree.qry(1, 1, n, l2, r2);
			tree.chg(1, 1, n, l1, r1, (len1 - 1.) / len1, sum2 / len2 / len1);
			tree.chg(1, 1, n, l2, r2, (len2 - 1.) / len2, sum1 / len1 / len2);
		}
		else {
			int l, r; scanf("%d%d", &l, &r);
			printf("%.10f\n", tree.qry(1, 1, n, l, r));
		}
		//rep(i, 1, n + 1) printf("%.2f%c", tree.qry(1, 1, n, i, i), " \n"[i == n]);
	}
}

int main() {
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}
