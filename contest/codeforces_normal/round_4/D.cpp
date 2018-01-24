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
const int N = 1e6 + 7;
int n, w0, h0;
struct Nd { 
	int w, h, id; 
	Nd() {}
	Nd(int w, int h, int id) : w(w), h(h), id(id) {}
};
struct Fenwick {
	static const int N = ::N;
	int n; pii mx[N];
	void ini(int _n = N - 1) { fill_n(mx + 1, n = _n, mp(-1, -1)); }
	void upd(int p, pii v) { for (; p <= n; p += p & -p) mx[p] = max(mx[p], v); }
	pii qry(int p) { pii r(-2, -2); for (; p; p -= p & -p) r = max(r, mx[p]); return r; }
}	fen;

vector<Nd> v;
bool cmpw(const Nd&a, const Nd&b) { return a.w < b.w; }

pii dp[N];
void solve() {
	v.clear();
	rep(i, 1, n + 1) {
		int wi, hi; scanf("%d%d", &wi, &hi);
		if (wi <= w0 || hi <= h0) continue;
		v.pb(Nd(wi, hi, i));
	}
	sort(all(v), cmpw);
	fen.ini();
	fen.upd(h0, mp(0, -1));
	for (int l = 0, r; l < sz(v); l = r) {
		r = l; while (r < sz(v) && v[r].w == v[l].w) r++;
		rep(i, l, r) dp[i] = fen.qry(v[i].h - 1), dp[i].fi++;
		rep(i, l, r) fen.upd(v[i].h, mp(dp[i].fi, i));
	}
	pii ans{0, -1};
	rep(i, 0, sz(v)) ans = max(ans, mp(dp[i].fi, i));
	printf("%d\n", ans.fi);
	vi met;
	for (int cur = ans.se; ~cur; cur = dp[cur].se) met.pb(v[cur].id);
	per(i, 0, sz(met)) printf("%d%c", met[i], " \n"[i == 0]);
}
int main() {
	while (~scanf("%d%d%d", &n, &w0, &h0)) solve();	

	return 0;
}