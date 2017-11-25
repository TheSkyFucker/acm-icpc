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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int n, x[N], y[N]; vi g[N];
map<int, int> px, py;
int far[N], cnt, cir;
void dfs(int u, int fa) {
	if (!px.count(x[u])) cnt++; px[x[u]] = u;
	if (!py.count(y[u])) cnt++; py[y[u]] = u;
	for (auto v : g[u]) {
		if (v == fa) continue;
		if (~far[v]) { cir = 1; continue; }
		far[v] = u;
		dfs(v, u);
	}
}

int pw2[N * 2];
void solve() {
	rep(i, 0, n) g[i].clear();px.clear();py.clear();
	rep(i, 0, n) { 
		int &x = ::x[i], &y = ::y[i]; scanf("%d%d", &x, &y);
		if (px.count(x)) { int j = px[x]; g[i].pb(j); g[j].pb(i); } px[x] = i;
		if (py.count(y)) { int j = py[y]; g[i].pb(j); g[j].pb(i); } py[y] = i;
	}
	int ans = 1;
	fill_n(far, n, -1);
	pw2[0] = 1;rep(i, 1, 2 * n + 1) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	rep(i, 0, n) if (!~far[i]) {
		px.clear();
		py.clear();
		far[i] = cnt = cir = 0;
		dfs(i, -1);
		ans = mul(ans, pw2[cnt] - !cir);
	}
	printf("%d\n", ans);
}
int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
