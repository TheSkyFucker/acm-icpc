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
const int N = 5e3 + 6, B = 2501;
int n, dp[N][N], mi[N];
vi g[N];
void dfs(int u, int f) {
	//dd(u); de(f);
	for (auto v : g[u]) if (v != f) dfs(v, u);
	rep(j, 0, B + 1) mi[j] = max(1, j);
	for (auto v : g[u]) if (v != f) {
		rep(j, -B, 0)
			dp[u][B + j] += dp[v][B + j + 1];
		rep(j, 0, B + 1) {
			dp[u][B + j] += dp[v][B - j];
			if (j < B)
			mi[j] = min(mi[j], dp[v][B + j + 1] - dp[v][B - j]);
		}
	}
	rep(j, 0, B + 1) dp[u][B + j] += mi[j];
	per(j, -B, B) dp[u][B + j] = min(dp[u][B + j], dp[u][B + j + 1]);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		int a, b; scanf("%d%d", &a, &b), a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
  printf("%d", dp[0][B]);
	
}
