#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
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
//-------
const int N = 2e5 + 7, INF = 1e9 + 7;
int n, m, cnt, cir;

struct Node {
	int l, r, tagl, tagr;
	Node() {}
	Node(int l, int r, int tagl, int tagr) : l(l), r(r), tagl(tagl), tagr(tagr) {}
	void set(const pii qv) {
		if (~qv.fi) l = tagl = qv.fi;
		if (~qv.se) r = tagr = qv.se;
	}
};
#define ls(o) ((o) << 1)
#define rs(o) ((o) << 1 | 1)
struct Tree {
	static const int N = ::N << 2;
	Node nd[N];
	void pushdown(int o) {
		nd[ls(o)].set({nd[o].tagl, nd[o].tagr});
		nd[rs(o)].set({nd[o].tagl, nd[o].tagr});
		nd[o].tagl = nd[o].tagr = -1;
	}
	void bud(int o, int l, int r) {
		nd[o] = Node(1, n, -1, -1);
		if (l == r) return;
		int mid = l + r >> 1;
		bud(ls(o), l, mid);
		bud(rs(o), mid + 1, r);
	}
	void chg(int o, int l, int r, const int ql, const int qr, const pii qv) {
		if (ql <= l && qr >= r) { nd[o].set(qv); return; }
		pushdown(o);
		int mid = l + r >> 1;
		if (ql <= mid) chg(ls(o), l, mid, ql, qr, qv);
		if (qr >  mid) chg(rs(o), mid + 1, r, ql, qr, qv);
	}
	pii qry(int o, int l, int r, int qx) {
		if (l == r) return {nd[o].l, nd[o].r};
		pushdown(o);
		int mid = l + r >> 1;
		if (qx <= mid) return qry(ls(o), l, mid, qx);
		else return qry(rs(o), mid + 1, r, qx);
	}
}	t[2];

struct Node2 {
	int l1, r1;
	Node2() {}
	Node2(int l1, int r1) : l1(l1), r1(r1) { }
	void meg(const Node2& ls, const Node2& rs) {
		l1 = min(ls.l1, rs.l1);
		r1 = max(ls.r1, rs.r1);
	}
};
struct Tree2 {
	static const int N = ::N << 2;
	Node2 nd[N];
	void bud(int o, int l, int r) {
		nd[o] = Node2(l, r);
		if (l == r) return;
		int mid = l + r >> 1;
		bud(ls(o), l, mid);
		bud(rs(o), mid + 1, r);
	}
	void upd(int o) { nd[o].meg(nd[ls(o)], nd[rs(o)]); }
	void chg(int o, int l, int r, int qx, int qv) {
		if (l == r) { nd[o] = qv ? Node2(l, l) : Node2(INF, 0); return; }
		int mid = l + r >> 1;
		if (qx <= mid) chg(ls(o),l, mid, qx, qv);
		else chg(rs(o), mid + 1, r, qx,qv);
		upd(o);
	}
	pii qry(int o, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r) return {nd[o].l1, nd[o].r1}; 
		int mid = l + r >> 1; pii ret = {INF, 0};
		if (ql <= mid) { 
			pii tmp = qry(ls(o), l, mid, ql, qr);
			ret.fi = min(ret.fi, tmp.fi);
			ret.se = max(ret.se, tmp.se);
		}
		if (qr >  mid) {
			pii tmp = qry(rs(o), mid + 1, r, ql, qr);
			ret.fi = min(ret.fi, tmp.fi);
			ret.se = max(ret.se, tmp.se);
		}
		return ret;
	}
}	tmm;

pii getcir(int y) {
	pii nd_up = t[0].qry(1, 1, n, y); 
	pii nd_dn = t[1].qry(1, 1, n, y); 
	int ql = max(nd_up.fi, nd_dn.fi);
	int qr = min(nd_up.se, nd_dn.se);
	return tmm.qry(1, 1, n, ql, qr);
}

void solve() {
	scanf("%d%d", &n, &m);
	cnt = n; cir = 1;
	t[0].bud(1, 1, n);
	t[1].bud(1, 1, n);
	tmm.bud(1, 1, n);

	rep(i, 0, m) {
		int tp, xa, ya, xb, yb; scanf("%d%d%d%d%d", &tp, &xa, &ya, &xb, &yb);
		int x = min(xa, xb), y = min(ya, yb);
		if (abs(ya - yb) == 1) {
			if (tp == 1) {
				pii c1 = getcir(y);
				pii c2 = getcir(y + 1);
				cir -= (c1.fi < c1.se) + (c2.fi < c2.se);
				pii ndl = t[x].qry(1, 1, n, y);
				pii ndr = t[x].qry(1, 1, n, y + 1);
				t[x].chg(1, 1, n, ndl.fi, y, {-1, ndr.se});
				t[x].chg(1, 1, n, y + 1, ndr.se, {ndl.fi, -1});
				pii c3 = getcir(y);
				if (c3.fi < c3.se) {
					cir++;
					cnt += c2.fi - 1 - c1.se + (c1.fi == c1.se) + (c2.fi == c2.se);
				}
			} else {
				pii c3 = getcir(y);
				cir -= c3.fi <= y && y < c3.se;
				pii nd = t[x].qry(1, 1, n, y);
				t[x].chg(1, 1, n, nd.fi, y, {-1, y});
				t[x].chg(1, 1, n, y + 1, nd.se, {y + 1, -1});
				if (c3.fi <= y && y < c3.se) {
					pii c1 = getcir(y);
				//	dd(c1.fi); de(c1.se);
					pii c2 = getcir(y + 1);
					//dd(c2.fi); de(c2.se);
					cir += (c1.fi < c1.se) + (c2.fi < c2.se);
					cnt -= c2.fi - 1 - c1.se + (c1.fi == c1.se) + (c2.fi == c2.se);
				}
			//	de(cir);
			//	de(cnt);
			}
		} else {
			if (tp == 1) {
				pii c = getcir(y);
				if (y < c.fi) cnt += c.fi - y + (c.fi == c.se);
				if (y > c.se) cnt += y - c.se + (c.fi == c.se);
				cir += c.fi == c.se;
				tmm.chg(1, 1, n, y, 1);
			} else {
				tmm.chg(1, 1, n, y, 0);
				pii c = getcir(y);
				if (y < c.fi) cnt -= c.fi - y + (c.fi == c.se);
				if (y > c.se) cnt -= y - c.se + (c.fi == c.se);
				cir -= c.fi == c.se;
			}
		}
		printf("%d\n", (n - cnt) * 2 + cir - 1);
	}

}

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 0, tcase) solve();
	return 0;
}
