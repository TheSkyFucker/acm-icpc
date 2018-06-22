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
struct ACA {
	static const int N = ::N, M = 52;
	int nxt[N][M], fail[N], _, vis[N];
	int ne() { fill_n(nxt[_], M, 0); vis[_] = 0; return _++; }
	void ini() { fail[_ = 0] = N - 1; ne(); }
	int val(char ch) { 
		if (ch >= 'A' && ch <= 'Z') return ch - 'A';
		return ch - 'a' + 26;
	}
	int ins(string s) {
		int u = 0;
		rep(i, 0, sz(s)) {
			int ch = val(s[i]);
			int &v = nxt[u][ch];
			if (!v) v = ne();
			u = v;
		}
		return u;
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
	void gao(int u) { while (u) vis[u] = true, u = fail[u]; }
	void solve(string s) {
		int u = 0;
		rep(i, 0, sz(s)) {
			int ch = val(s[i]);
			u = nxt[u][ch];
			gao(u);
		}
	}
}	ac;
int pos[N];
void solve() {
	string s; cin >> s;
	int q; cin >> q;
	ac.ini();
	rep(i, 0, q) {
		string t; cin >> t;
		pos[i] = ac.ins(t);
	}
	ac.solve(s);
	rep(i, 0, q) cout << "ny"[ac.vis[pos[i]]] << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int tcas; cin >> tcas;
  rep(cas, 0, tcas) solve();
	return 0;
}
