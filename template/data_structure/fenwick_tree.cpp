// index : [1, n]
// time : nlogn
// support : segment add, sum
// !!!! : use before init()!
struct Fenwick {
	static const int N = 2e5 + 7;
	ll a1[N], a2[N]; int n;
	void init(int _n) { n = _n; }
	void add(ll *a, int p, ll v) { for (; p <= n; p += p & -p) a[p] += v; }
	void add(int l, int r, ll v) { //[l, r]
		add(a1, l, v), add(a1, r + 1, -v);
		add(a2, l, -v * (l - 1)), add(a2, r + 1, v * r);
	}
	ll sum(ll *a, int p) { ll r = 0; for (; p > 0; p -= p & -p) r += a[p]; return r; }
	ll pre(int p) { return !p ? 0 : sum(a1, p) * p + sum(a2, p); }
	ll sum(int l, int r) { return pre(r) - pre(l - 1); } //[l, r]
}	fen;
