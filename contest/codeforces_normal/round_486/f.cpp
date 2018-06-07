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
const int N = 2e3 + 7, INF = 1e9 + 7;
int n, dp[N][N], w[N];
vi gu[N];
bool rain[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n; n++;
	int rn; cin >> rn;
	int un; cin >> un; un++;
	rep(i, 0, rn) {
		int l, r; cin >> l >> r;
		rep(j, l, r) rain[j] = true;
	}
	rep(i, 1, un) {
		int x; cin >> x >> w[i];
		gu[x].pb(i);
	}
	rep(i, 0, n) fill_n(dp[i], un, INF);
	dp[0][0] = 0;
	rep(i, 0, n) {
		rep(j, 1, un) dp[i][0] = min(dp[i][0], dp[i][j]);
		for (auto u : gu[i]) dp[i][u] = min(dp[i][u], dp[i][0]);
		rep(j, 1, un) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + w[j]);
		if (!rain[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
	}
	cout << (dp[n - 1][0] < INF ? dp[n - 1][0] : -1);
	return 0;
}
