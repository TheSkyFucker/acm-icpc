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
const int N = 1e2 + 8;
ll m; int k;
ll C[N][N];

vi v;
ll dp[N][N];
ll dfs(int pos, int k, bool up) {
	if (pos < 0 || k <= 0) return k == 0;
	if (!up && ~dp[pos][k]) return dp[pos][k];
	ll ret = 0;
	if (!up) ret = C[pos + 1][k];
	else {
		int lim = v[pos];
		rep(i, 0, lim + 1) {
			ret += dfs(pos - 1, k - i, up && i == lim);
		}
	}
	if (!up) dp[pos][k] = ret;
	return ret;
}

ll solve(ll mid) {
	if (!mid) return 0;
	v.clear();
	for (ll tmp = mid; tmp; tmp >>= 1) v.pb(tmp & 1);
	return dfs(sz(v) - 1, k, true);
}
int main() {
	memset(dp, -1, sizeof(dp));
	rep(i, 0, N) C[i][0] = 1;
	rep(i, 1, N) rep(j, 1, i + 1) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	//rep(i, 0, 10) rep(j, 0, i + 1) printf("%lld%c", C[i][j], " \n"[j == i]);
	scanf("%lld%d", &m, &k);
	ll ans = -1;
	for (ll l = 1, r = 1e18, mid = l + r >> 1; l <= r; mid = l + r >> 1) {
		solve(mid * 2) - solve(mid) >= m ? r = (ans = mid) - 1 : l = mid + 1;
	}
	printf("%lld", ans);
	return 0;
}
