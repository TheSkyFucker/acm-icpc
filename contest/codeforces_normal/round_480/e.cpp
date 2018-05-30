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
int n, k;
vi g[N];
int far[N];
int dep = 0;
void bud(int u) {
	for (auto v : g[u]) {
		if (v == far[u]) continue;
		far[v] = u;
		bud(v);
	}
}
bool use[N];
int st[N][20];
int gao(int u) {
	int ret = 1;
	per(i, 0, 20) if (!use[st[u][i]]) {
		u = st[u][i];
		ret += pw(i);
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> k;
	rep(i, 0, n - 1) {
		int a, b; cin >> a >> b, a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	far[n - 1] = n - 1;
	bud(n - 1);
	rep(i, 0, n) st[i][0] = far[i];
	rep(j, 1, 20) rep(i, 0, n) st[i][j] = st[st[i][j - 1]][j - 1];
	vi ans;
	int can = n - k - 1;
	use[n - 1] = true;
	per(i, 0, n - 1) if (!use[i]) {
		int ned = gao(i);
		if (can >= ned) {
			can -= ned;
			for (int u = i; !use[u]; u = far[u]) use[u] = true;
		}
		else ans.pb(i);
	}
	per(i, 0, sz(ans)) printf("%d%c", ans[i] + 1, " \n"[i == 0]);
	return 0;
}
