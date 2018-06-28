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
const int N = 3e5 + 7;

namespace BCC {
	const int N = ::N;
	vi ng[N]; int dfn[N], low[N], id[N], st[N], _st, _;
	void dfs(int c, int dep, vi g[]) {
		int cc = 0; st[_st++] = c; dfn[c] = low[c] = dep;
		for (auto t : g[c]) {
			if (!dfn[t]) {
				dfs(t, dep + 1, g); 
				low[c] = min(low[c], low[t]);
			} else if (dfn[t] != dfn[c] - 1 || cc++)
				low[c] = min(low[c], dfn[t]);
		}
		if (low[c] == dfn[c]) {
			do { id[st[--_st]] = _; } while (st[_st] != c); 
			_++; 
		}
	}
	int dep[N];
	int gao(int &rt, int u, int fa, vi g[]) {
		if (dep[rt] < dep[u]) rt = u;
		for (auto v : g[u]) {
			if (v == fa) continue;
			dep[v] = dep[u] + 1;
			gao(rt, v, u, g);
		}
	}
	int solve(int n, vi g[]) {
		rep(i, 0, n) if (!dfn[i]) dfs(i, 1, g);
		rep(i, 0, n) for (auto j : g[i]) if (id[i] != id[j])
			ng[id[i]].pb(id[j]);
		int rt = 0;
		gao(rt, 0, -1, ng);
		fill_n(dep, _, 0);
		gao(rt, rt, -1, ng);
		cout << dep[rt];
	}
};

int n, m;
vi g[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> n >> m;
  rep(i, 0, m) {
  	int a, b; cin >> a >> b, a--, b--;
  	g[a].pb(b);
  	g[b].pb(a);
	}
	BCC::solve(n, g);
	return 0;
}
