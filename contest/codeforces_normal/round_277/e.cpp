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
const int N = 1e5 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD ;}
struct Fenwick {
	int n;
	pii dp[N];
	void ini(int _n) { n = _n; fill_n(dp + 1, n, mp(0, 0)); }
	void upd(int p, pii v) {
		for (; p <= n; p += p & -p) {
			if (dp[p].fi == v.fi)
				dp[p].se = add(dp[p].se, v.se);
			else if (dp[p].fi < v.fi)
				dp[p] = v;
		}
	}
	pii qry(int p) {
		pii ret = {0, 1};
		for (; p; p -= p & -p) {
			if (ret.fi == dp[p].fi)
				ret.se = add(ret.se, dp[p].se);
			else if (ret.fi < dp[p].fi)
				ret = dp[p];
		}
		return ret;
	}
}	fen;
int n, a[N];
pii dp[N], pd[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	fen.ini(100000);
	int mx = 0;
	rep(i, 0, n) {
		dp[i] = fen.qry(a[i] - 1);
		dp[i].fi++;
		mx = max(mx, dp[i].fi);
		fen.upd(a[i], dp[i]);
	}
	rep(i, 0, n) a[i] = 100001 - a[i];
	fen.ini(100000);
	per(i, 0, n) {
		pd[i] = fen.qry(a[i] - 1);
		pd[i].fi++;
		fen.upd(a[i], pd[i]);
	}
	int tot = 0;
	rep(i, 0, n) if (dp[i].fi == mx) tot = add(tot, dp[i].se);
	rep(i, 0, n) {
		if (dp[i].fi + pd[i].fi < mx + 1) putchar('1');
		else if (mul(dp[i].se, pd[i].se) == tot) putchar('3');
		else putchar('2');
	}
			
	return 0;
}
