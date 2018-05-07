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
const int N = 1e5 + 7;
int n;
int ans = 0;
bool lef[N];
vi g[N];
struct Trie {
	static const int N = ::N;
	int son[N][26], id[N];
	int ne() { fill_n(son[n], 26, -1); return n++; }
	void ini() { n = 0; ne(); }
	void insert(const string &s) {
		int u = 0;
		for (auto ch : s) {
			int &v = son[u][ch - 'a'];
			if (!~v) { v = ne(); g[u].pb(v); }
			u = v;
		}
		lef[u] = true;
	}
	multiset<int> Set[N];
	void dfs(int u, int dep = 0) {
		for (auto v : g[u]) {
			dfs(v, dep + 1);
			for (auto e : Set[v]) Set[u].insert(e);
		}
		if (lef[u]) {
			Set[u].insert(dep);
			ans += dep;
		}
		else if (u) {
			auto mx = Set[u].rbegin();
			ans -= *mx - dep;
			Set[u].erase(Set[u].find(*mx));
			Set[u].insert(dep);
		}
		//if (u == 3) for (auto e : Set[u]) de(e);
	}
}	trie;

int main() {
  int m; scanf("%d", &m);
  trie.ini();
  rep(i, 0, m) {
  	string str; cin >> str;
		trie.insert(str);
	}
	trie.dfs(0);
	printf("%d", ans);
	return 0;
}
