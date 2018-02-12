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
int n, f[N], vis[N], deg[N];
int gao(int u) {
	vis[u] = true;
	return vis[f[u]] ? u : gao(f[u]);
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		scanf("%d", &f[i]); f[i]--;
		deg[f[i]]++;
	}
	vector<pii> v;
	int remain = 0;
	rep(i, 0, n) if (!deg[i]) v.pb({i, gao(i)}), remain++;
	rep(i, 0, n) if (!vis[i]) v.pb({i, gao(i)});
	if (!remain && sz(v) == 1) { puts("0"); return 0; }
	printf("%d\n", sz(v)); 
//	for (auto e : v) { dd(e.fi + 1); de(e.se + 1); }
	v.pb(v[0]);
	rep(i, 0, sz(v) - 1) printf("%d %d\n", v[i].se + 1, v[i + 1].fi + 1);

	return 0;
}
