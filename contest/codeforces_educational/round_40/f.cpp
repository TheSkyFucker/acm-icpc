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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e4 + 7, MOD = 1e9 + 7;
const int bas[3][3] = {{1, 1 ,0}, {1, 1, 1}, {0, 1, 1}};
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }

struct Mat {
	int a[3][3];
	Mat() {}
	Mat(int d) { rep(i, 0, 3) rep(j, 0, 3) a[i][j] = d * (i == j); }
	Mat(const int b[3][3]) { rep(i, 0, 3) rep(j, 0, 3) a[i][j] = b[i][j]; }
	Mat operator *(const Mat &b) const {
		Mat r(0);
		rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3)
			r.a[i][j] = add(r.a[i][j], mul(a[i][k], b.a[k][j]));
		return r;
	}
	void out() {
		rep(i, 0, 3) rep(j, 0, 3) printf("%d%c", a[i][j], " \n"[j == 2]);
	}
};
Mat pw[8][100];
int n, cnt[10]; ll m;
int main() {
	scanf("%d%lld", &n, &m);
	vector<pair<ll, int> > v;
	rep(i, 0, n) {
		int a; ll l, r; scanf("%d%lld%lld", &a, &l, &r);
		v.pb({l, a});
		v.pb({r + 1, -a});
	}
	v.pb({m, 1});
	v.pb({m, 3});
	sort(all(v));
	rep(i, 0, 8) {
		pw[i][0] = bas;
		rep(j, 0, 3) if (i & pw(j)) rep(k, 0, 3) pw[i][0].a[k][j] = 0;
		rep(j, 1, 61) pw[i][j] = pw[i][j - 1] * pw[i][j - 1];
	}
	Mat ans(1);
	ll pre = 2;
	int cur = 0;
	for (int l = 0, r; l < sz(v); l = r) {
		r = l; 
		while (r < sz(v) && v[r].fi == v[l].fi) { 
			if (v[r].se > 0) cnt[v[r].se]++;
			else cnt[-v[r].se]--;
			r++;
		}
		int nxt = 0;
		rep(i, 0, 3) nxt |= (cnt[i + 1] > 0) << i;
		Mat tmp(1);
		ll ned = v[l].fi - pre;
		per(i, 0, 61) if (ned & pw(i)) tmp = tmp * pw[cur][i];
		ans = ans * tmp;
		pre = v[l].fi;
		cur = nxt;
	}
	ans = ans * pw[cur][0];
	printf("%d", ans.a[1][1]);
	return 0;
}
