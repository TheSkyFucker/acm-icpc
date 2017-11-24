#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define debug(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
const int N = 1e5 + 7;
int n, m, c[N];
vi g[N];
bool vis[N];
struct UF {
	int far[N];
	void init() { rep(i, 0, N) far[i] = i; }
	int getf(int d) { return far[d] == d ? d : far[d] = getf(far[d]); }
	bool same(int a, int b) { return getf(a) == getf(b); }
	void comb(int a, int b) {
		if (same(a = getf(a), b = getf(b))) return;
		if (c[a] < c[b]) swap(a, b);
		far[a] = b;
	}
}	uf;
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n + 1) scanf("%d", c + i);
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	uf.init();
	rep(i, 1, n + 1) if (!vis[i]) {
		queue<int> que; que.push(i); vis[i] = true;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (auto v : g[u]) {
				if (vis[v]) continue;
				vis[v] = true; uf.comb(u, v);
				que.push(v);
			}
		}
	}
	ll ans = 0;
	rep(i, 1, n + 1) if (uf.getf(i) == i) ans += c[i];
	printf("%lld\n", ans);
	return 0;

}
