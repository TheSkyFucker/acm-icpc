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
string str[N];
int n, m;
vi g[N];
pii dis[N];
map<string, int> Map;
int gao(string str) {
		rep(i, 0, sz(str)) str[i] = tolower(str[i]);
		if (!Map.count(str)) {
			int sz = sz(Map);
			Map[str] = sz;
			dis[sz].se = -sz(str);
			rep(i, 0, sz(str)) if (str[i] == 'r') dis[sz].fi--;
		}
		return Map[str];
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		cin >> str[i];
		gao(str[i]);
	}
  scanf("%d", &m);
  rep(i, 0, m) {
  	string a, b; cin >> a >> b;
  	int ida = gao(a), idb = gao(b);
  	g[idb].pb(ida);
	}
	priority_queue<pair<pii, int> > stk;
	rep(i, 0, sz(Map)) stk.push({dis[i], i});
	while (!stk.empty()) {
		auto u = stk.top(); stk.pop();
		if (u.fi != dis[u.se]) continue;
		for (auto v : g[u.se]) {
			if (dis[v] < dis[u.se]) {
				dis[v] = dis[u.se];
				stk.push({dis[v], v});
			}
		}
	}
	pair<int, ll> ans;
	rep(i, 0, n) {
		ans.fi -= dis[gao(str[i])].fi;
		ans.se -= dis[gao(str[i])].se;
	}
	printf("%d %lld", ans.fi, ans.se);
	return 0;

}

