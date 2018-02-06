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
const int N = 1e6 + 7;
int n;
struct P { int a, b, c; void read() { scanf("%d%d%d", &a, &b, &c); b = -b; } } p[N];
bool cmpa(const P&a, const P&b) { return a.a > b.a; }
struct Fenwick {
	static const int N = ::N;
	int a[N], n;
	void ini(int _n = N - 1) { fill_n(a + 1, n = _n, 0); }
	void upd(int p, int v) { for (; p <= n; p += p & -p) a[p] = max(a[p], v); }
	int qry(int p) { int r = 0; for (; p; p -= p & -p) r = max(r, a[p]); return r; }
}	fen;
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &p[i].a);
	rep(i, 0, n) scanf("%d", &p[i].b), p[i].b = -p[i].b;
	rep(i, 0, n) scanf("%d", &p[i].c);
	sort(p, p + n, cmpa);
	vi v; v.resize(n);
	rep(i, 0, n) v[i] = p[i].b; 
	sort(all(v)); v.erase(unique(all(v)), v.end());
	rep(i, 0, n) p[i].b = lower_bound(all(v), p[i].b) - v.begin() + 1;
	//rep(i, 0, n) { dd(p[i].a); dd(p[i].b); de(p[i].c); }
  int ans = 0;
  fen.ini(sz(v));
  for (int l = 0, r; l < n; l = r) {
  	r = l; while (r < n && p[r].a == p[l].a) r++;
		rep(i, l, r) if (fen.qry(p[i].b - 1) > p[i].c) ans++;
		rep(i, l, r) fen.upd(p[i].b, p[i].c);
	}
	printf("%d\n", ans);
	return 0;
}
