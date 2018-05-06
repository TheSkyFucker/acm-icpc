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
const int N = 2e5 + 7;
vi g[N];
int n, m, vis[N];
bool gao(int rt) {
	vi q; q.pb(rt); vis[rt] = true;
	rep(i, 0, sz(q)) {
		for (auto v : g[q[i]]) {
			if (!vis[v]) {
				vis[v] =true;
				q.pb(v);
			}
		}
	}
	if (sz(q) <= 2) return false;
	rep(i, 0, sz(q)) if (sz(g[q[i]]) != 2) return false;
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b), a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans = 0;
	rep(i, 0, n) if (!vis[i]) if (gao(i)) ans++;
	printf("%d", ans);

	return 0;
}
