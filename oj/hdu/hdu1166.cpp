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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
// index : [0, n)
// leaf : [m, m + n]
// space : 2 * (2 ^ (log(N - 1) + 1))
#define ls(o) ((o) << 1)
#define rs(o) ((o) << 1 | 1)
struct ZKW {
	static const int N = (1 << 17) + 7;
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
	ll qry(int l, int r) { // !! [l, r) && l < r
		ll ret = 0;
		for (int u = l + m, v = r + m; u < v; u >>= 1, v >>= 1) {
			if (u & 1) ret += t[u++];
			if (v & 1) ret += t[--v];
		}
		return ret;
	}
}	zkw;

const int N = 5e4 + 7;
int n, a[N];
void solve() {
	scanf("%d", &n); rep(i, 0, n) scanf("%d", &a[i]);
	zkw.bud(n, a);
	char op[10];
	while (~scanf(" %s", op) && strcmp(op, "End") != 0) {
		if (op[0] == 'Q') {
			int l, r; scanf("%d%d", &l, &r); l--;
			printf("%lld\n", zkw.qry(l, r));
		}
		else {
			int p, v; scanf("%d%d", &p, &v); p--;
			if (op[0] == 'S') v = -v;
			zkw.add(p, v);
		}
	}
}

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 1, tcase + 1) {
		printf("Case %d:\n", icase);
		solve();
	}
	return 0;
}

