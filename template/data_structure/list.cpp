// desc : list, middle number
int ans[M];
struct List {
	static const int N = 1e2 + 7;
	int m, sz, l[N], r[N];
	void ini(int n) {
		sz = n;
		rep(i, 0, n + 1) r[i] = i + 1;
		rep(i, 1, n + 2) l[i] = i - 1;
		m = n + 1 >> 1;
	}
	pii st[1000000]; int tp;
	void del(int p) {
		st[++tp].se = m;
		if (sz & 1) { if (p >= m) m = l[m]; }
		else { if (p <= m) m = r[m]; }
		st[tp].fi = p;
		r[l[p]] = r[p];
		l[r[p]] = l[p];
		sz--;
	}
	void pop() { r[l[st[tp].fi]] = l[r[st[tp].fi]] = st[tp].fi; m = st[tp--].se; sz++; }
	int mid() { return (sz & 1) ? (ans[m] << 1) : (ans[m] + ans[r[m]]); }
}	L;
