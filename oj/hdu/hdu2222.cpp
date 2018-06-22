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
// desc : 'a' .. 'z' | 0 is root | N-1 is virtual
// !!!! : ini() -> ins() -> bud()
struct ACA {
	static const int N = ::N, M = 26;
	int nxt[N][M], fail[N], fa[N], _, lef[N];
	int ne() { fill_n(nxt[_], M, 0); lef[_] = 0; return _++; }
	void ini() { fail[_ = 0] = N - 1; ne(); }
	void ins(string s) {
		int u = 0;
		rep(i, 0, sz(s)) {
			int &v = nxt[u][s[i] - 'a']; // modify
			if (!v) fa[v = ne()] = u;
			u = v;
		}
		lef[u]++;
	}
	void bud() {
		vi v; v.pb(0);
		rep(_u, 0, sz(v)) {
			int u = v[_u];
			rep(i, 0, M) nxt[u][i] 
				? v.pb(nxt[u][i]), fail[nxt[u][i]] = nxt[fail[u]][i]
				: nxt[u][i] = nxt[fail[u]][i];
		}
	}
	int gao(int u) { int r = 0; while(u) r += lef[u], lef[u] = 0, u = fail[u]; return r; }
	void solve(string s) {
		int u = 0, ans = 0;
		rep(i, 0, sz(s)) {
			int c = s[i] - 'a';
			u = nxt[u][c];
			ans += gao(u);
		}
		cout << ans << endl;
	}
}	ac;

void solve() {
	ac.ini();
	int n; cin >> n;
	rep(i, 0, n) {
		string s; cin >> s;
		ac.ins(s);
	}
	ac.bud();
	string s; cin >> s;
	ac.solve(s);
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int tcas; cin >> tcas;
  rep(cas, 0, tcas) solve();
	return 0;
}
