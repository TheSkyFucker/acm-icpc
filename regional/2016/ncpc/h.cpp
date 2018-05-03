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
const int N = 5e5 + 7;

map<int, int> Map;
int val[N], _ = 0;
int gid(int x) {
	if (Map.count(x)) return Map[x];
	val[_] = x;
	return Map[x] = _++;
}

int n;
bool vis[N];
vi g[N];

int main() {
	scanf("%d", &n);
	ll ans = 0;
	rep(i, 0, n) {
		int s, t; scanf("%d%d", &s, &t);
		ans += s;
		ans += t;
		s = gid(s);
		t = gid(t);
		g[s].pb(t); 
		g[t].pb(s); 
	}
	ll cut = 0;
	rep(i, 0, _) cut += val[i];
	rep(i, 0, _) if (!vis[i]) {
		vis[i] = true;
		queue<int> que; que.push(i);
		int mx = -INT_MAX, eg = 0, nd = 0;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			mx = max(mx, val[u]); 
			nd += 1;
			eg += sz(g[u]);
			for (auto v : g[u]) {
				if (!vis[v]) {
					vis[v] = true;
					que.push(v);
				}
			}
		}
		assert(abs(nd - eg / 2) <= 1);
		if (nd * 2 != eg) cut -= mx;
	}

	printf("%lld", ans - cut);
	return 0;
}
