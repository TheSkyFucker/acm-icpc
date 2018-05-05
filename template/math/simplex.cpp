// n - variables, m - equations
// max F(X) = CX
// s.t. AX <= B, X >= 0
// C[1..n]       => a[0][1..n]
// B[1..m]       => a[1..m][0]
// A[1..m][1..n] => a[1..m][1..n]
// answer : F(X) => -a[0][0] , X => x[1..n]
// ini() : false => infeasible
// sol() : false => unbounded
const int N = 25;
const db eps = 1e-8, dinf = 1e15;
int sgn(db d) { return (d > eps) - (d < -eps); }
struct Simplex {
	static const int N = ::N;
	int n, m;
	db a[N][N], x[N];
	int id[N << 1], q[N];
	void pivot(int l, int e){
    swap(id[n + l], id[e]);
    db t = a[l][e]; a[l][e] = 1;
    rep(j, 0, n + 1) a[l][j] /= t;
    rep(i, 0, m + 1) if (i != l && sgn(a[i][e])) {
      t = a[i][e]; a[i][e] = 0;
      rep(j, 0, n + 1) a[i][j] -= a[l][j] * t;
		}
	}
	bool ini(int _n, int _m, db A[N][N], db B[N], db C[N]) {
		srand(317);
		n = _n, m = _m;
		rep(i, 1, n + 1) a[0][i] = C[i];
		rep(i, 1, m + 1) { rep(j, 1, n + 1) a[i][j] = A[i][j]; a[i][0] = B[i]; }
		rep(i, 1, n + 1) id[i] = i;
		while (1) {
			int e = 0, l = 0;
			rep(i, 1, m + 1) if (sgn(a[i][0]) < 0 && (!l || (rand() & 1))) l = i; if (!l) break;
			rep(j, 1, n + 1) if (sgn(a[l][j]) < 0 && (!e || (rand() & 1))) e = j;	if (!e) return false;
			pivot(l, e);
		}
		return true;
	}
	bool solve() {
		while (1) {
			int l = 0, e = 0; db mn = dinf;
			rep(j, 1, n + 1)
				if (sgn(a[0][j]) > 0) { e = j; break; }
			if (!e) break;
			rep(i, 1, m + 1) if (sgn(a[i][e]) > 0 && a[i][0] / a[i][e] < mn)
				mn = a[i][0] / a[i][e], l = i;
			if (!l) return false;
			pivot(l, e);
		}
		rep(i, 1, m + 1) x[id[n + i]] = a[i][0];
		return true;
	}
}	sp;
