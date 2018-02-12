const int MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
struct Mat {
	vector<vi> a;
	Mat() {}
	Mat(int n, int v = 1) { a.resize(n, vi(n)); rep(i, 0, n) a[i][i] = v; }
	Mat operator *(const Mat &b) const {
		int n = sz(a); Mat r(n, 0);
		rep(i, 0, n) rep(j, 0, n) rep(k, 0, n)
			r.a[i][j] = add(r.a[i][j], mul(a[i][k], b.a[k][j]));
		return r;
	}
	Mat operator ^(ll b) {
		int n = sz(a); Mat r(n), t = *this;
		for (; b; b >>= 1) {
			if (b & 1) r = r * t;
			t = t * t;
		}
		return r;
	}
	void out() {
		for (auto r : a) rep(i, 0, sz(r)) printf("%d%c", r[i], " \n"[i == sz(r) - 1]);
	}
};
