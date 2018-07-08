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
const int N = 4e2 + 7, MOD = 1e9 + 7;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int n, c, a[N], b[N], g[N][N], dp[N][N];
int sum(int p, int a, int b) { return add(g[p][b], MOD - g[p][a - 1]); }
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> c;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) cin >> b[i];
  rep(j, 1, N) g[0][j] = 1;
  rep(i, 1, N) rep(j, 1, N) g[i][j] = mul(g[i - 1][j], j);
	rep(i, 0, N) rep(j, 1, N) inc(g[i][j], g[i][j - 1]);
	rep(j, 0, c + 1) dp[1][j] = sum(j, a[1], b[1]);
	rep(i, 2, n + 1)
		rep(j, 0, c + 1)
			rep(ci, 0, j + 1)
				inc(dp[i][j], mul(dp[i - 1][j - ci], sum(ci, a[i], b[i])));
	cout << dp[n][c];
	return 0;
}
