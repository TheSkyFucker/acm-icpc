// index : [0, n)
// leaf : [m, m + n]
// space : 2 * (2 ^ (log(N - 1) + 1))
// note : node change && segment query
#define ls(o) ((o) << 1)
#define rs(o) ((o) << 1 | 1)
struct ZKW {
	static const int N = (1 << 20) + 7;
	int n, m; ll t[N];
	void upd(int o) { t[o] = t[ls(o)] + t[rs(o)]; }
	void bud(int _n, int * a) {
		n = _n; 
		m = 1; while (m < n) m <<= 1;
		fill_n(t + m, m, 0);
		rep(o, 0, n) t[m + o] = a[o];
		per(o, 1, m) upd(o); 
	}
	void add(int p, ll v) { t[p += m] += v;while (p >>= 1) upd(p); }
	void chg(int p, ll v) { t[p += m] = v; while (p >>= 1) upd(p); }
	ll qry(int l, int r) { //qry [l, r) && l < r
		ll ret = 0;
		for (int u = l + m, v = r + m; u < v; u >>= 1, v >>= 1) {
			if (u & 1) ret += t[u++];
			if (v & 1) ret += t[--v];
		}
		return ret;
	}
}	zkw;


