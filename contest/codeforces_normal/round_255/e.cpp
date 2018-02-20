#include<bits/stdc++.h>
using namespace std;
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

const int N = 3e5 + 7, MOD = 1e9 + 9;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int n, m, a[N], s[N], f[N];
int F(int a, int b, int x) {
	//Fi = f(i - 1) * b + f(i - 2) * a
	if (x == 1) return a;
	if (x == 2) return b;
	return add(mul(f[x - 1], b), mul(f[x - 2], a));
}
int S(int a, int b, int x) { return add(F(a, b, x + 2), MOD - b); }
struct Nd {
	int a, b, sum;
	void add(int _a, int _b, int sz) {
		sum = ::add(sum, S(_a, _b, sz));
		a = ::add(a, _a);
		b = ::add(b, _b);
	}
};
struct Tree {
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
	static const int N = ::N << 2;
	Nd nd[N];
	void dwn(int o, int l, int r) {
		int &a = nd[o].a, &b = nd[o].b, m = l + r >> 1;
		nd[ls].add(a, b, m - l + 1);
		nd[rs].add(F(a, b, m - l + 2), F(a, b, m - l + 3), r - m);
		a = b = 0;
	}
	void add(int o, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) { nd[o].add(f[l - ql + 1], f[l - ql + 2], r - l + 1); return; }
		else dwn(o, l, r);
		int m = l + r >> 1;
		if (ql <= m) add(ls, l, m, ql, qr);
		if (qr >  m) add(rs, m + 1, r, ql, qr);
		nd[o].sum = ::add(nd[ls].sum, nd[rs].sum);
	}
	int qry(int o, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return nd[o].sum;
		else dwn(o, l, r);
		int m = l + r >> 1, ret = 0;
		if (ql <= m) ret = ::add(ret, qry(ls, l, m, ql, qr));
		if (qr >  m) ret = ::add(ret, qry(rs, m + 1, r, ql, qr));
		return ret;
	}
}	tree;
int main() {
	f[1] = 1; rep(i, 2, N) f[i] = add(f[i - 1], f[i - 2]);
	scanf("%d%d", &n, &m);
	rep(i, 1, n + 1) scanf("%d", a + i), s[i] = add(s[i - 1], a[i]);
	rep(i, 0, m) {
		int tp, l, r; scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) tree.add(1, 1, n, l, r);
		else printf("%d\n", add(tree.qry(1, 1, n, l, r), add(s[r], MOD - s[l - 1])));
	}
	return 0;
}
