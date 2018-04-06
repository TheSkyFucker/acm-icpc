#include<bits/stdc++.h>
using namespace std;
typedef long double db;
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
const int N = 1e5 + 7;
int n, w;
struct FS {
	int fz, fm;
	FS() {}
	FS(int _fz, int _fm) {
		int g = __gcd(_fz, _fm);
		fz = _fz / g;
		fm = _fm / g;
	}
	bool operator <(const FS& b) const { return 1ll * fz * b.fm < 1ll * b.fz * fm; }
	bool operator >(const FS& b) const { return b < *this; }
	bool operator ==(const FS& b) const { return 1ll * fz * b.fm == 1l * b.fz * fm; }
	bool operator <=(const FS& b) const { return !(*this > b); }
	bool operator >=(const FS& b) const { return !(*this < b); }
};
	
struct Fenwick {
	static const int N = ::N << 1;
	int a[N], n;
	void ini(int _n) { n = _n; fill_n(a + 1, n, 0); }
	void add(int p, int v) { for (; p <= n; p += p & -p) a[p] += v; }
	int qry(int p) { int r = 0; for (; p; p -= p & -p) r += a[p]; return r; }
}	fen;
vector<pair<FS, FS> > v[2];
vector<FS> tab;
int gpos(const FS &d) { return lower_bound(all(tab), d) - tab.begin() + 1; }
ll solve(vector<pair<FS, FS> > v0, vector<pair<FS, FS> > v1) {
	fen.ini(sz(tab));
	ll ret = 0;
	per(j, 0, sz(v1)) {
		while (!v0.empty() && v0.back().fi >= v1[j].fi) {
			fen.add(gpos(v0.back().se), 1);
			v0.pop_back();
		}
		ret += fen.qry(gpos(v1[j].se));
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &w);
	rep(i, 0, n) {
		int x, v; scanf("%d%d", &x, &v); if (v < 0) v = -v;
		if (x > 0)
			::v[0].pb({FS(x, (v + w)), FS(x, (v - w))});
		else {
			x = -x;
			::v[0].pb({FS(x, (v - w)), FS(x, (v + w))});
		}
	}
	v[1] = v[0];
	rep(i, 0, 2) sort(all(v[i]));
	rep(i, 0, 2) rep(j, 0, sz(v[i])) tab.pb(v[i][j].se);
	sort(all(tab));
	tab.erase(unique(all(tab)), tab.end());
	ll ans = solve(v[0], v[1]);
	map<pair<FS, FS> , int> Map;
	for (auto e : v[0]) {
		ans -= ++Map[e];
	}
	cout << ans;
	return 0;
}
