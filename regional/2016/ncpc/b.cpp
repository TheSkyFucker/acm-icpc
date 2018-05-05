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
vi g[N];
// 'a' .. 'z'
// !!!! : ini() 
struct Trie {
	int son[N][26], _;
	int ne() { fill_n(son[_], 26, -1); return _++; }
	void ini() { _ = 0; ne(); }
	int insert(const string &s, bool l = false) {
		int u = 0; vi path; 
		for (auto ch : s) {
			int &v = son[u][ch - 'a'];
			if (!~v) path.pb(v = ne());
			u = v;
		}
		if (l) for (auto p : path) g[p].pb(u);
		return u;
	}
}	tree;

int dis[N];
void dij(int n, int s) {
	fill_n(dis, n, INT_MAX); dis[s] = 0;
	priority_queue<pii> stk; stk.push({-dis[s], s});
	while (!stk.empty()) {
		int _d, u;
		tie(_d, u) = stk.top(); stk.pop();
		if (_d != -dis[u]) continue;
		for (auto v : g[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				stk.push({-dis[v], v});
			}
		}
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	tree.ini();
	rep(i, 0, n) {
		string str;
		cin >> str;
		tree.insert(str, true);
	}
	vi q;
	rep(i, 0, m) {
		string str;
		cin >> str;
		q.pb(tree.insert(str));
	}
	rep(i, 0, tree._) {
		rep(j, 0, 26) {
			int s = tree.son[i][j];
			if (~s) g[i].pb(s), g[s].pb(i);
		}
	}
	dij(tree._, 0);
	for (auto qi : q) printf("%d\n", dis[qi]);
	return 0;
}
