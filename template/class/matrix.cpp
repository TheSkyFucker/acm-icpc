const int MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
struct Mat {
	static const int N = 100;
	int a[N][N], n;
	Mat() {}
	Mat(vector<vi> v) {
		n = sz(v);
		rep(i, 0, n) rep(j, 0, n) a[i][j] = v[i][j];
	}
	Mat(int _n, int v) { 
		n = _n;
		rep(i, 0, n) {
			fill_n(a[i], n, 0);
			a[i][i] = v;
		}
	}
	Mat operator *(const Mat &b) const {
		Mat r(n, 0);
		rep(i, 0, n) rep(j, 0, n) rep(k, 0, n)
			r.a[i][j] = add(r.a[i][j], mul(a[i][k], b.a[k][j]));
		return r;
	}
	Mat operator ^(ll b) {
		Mat r(n, 1), t = *this;
		for (; b; b >>= 1) {
			if (b & 1) r = r * t;
			t = t * t;
		}
		return r;
	}
	void out() {
		rep(i, 0, n) rep(j, 0, n) printf("%d%c", a[i][j], " \n"[j == n - 1]);
	}
};
