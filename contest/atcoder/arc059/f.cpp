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
const int N = 5e3 + 7, MOD = 1e9 + 7;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int n, m, dp[N][N], g[N][N], pw[N];
int main() {
  pw[0] = 1; rep(i, 1, N) pw[i] = mul(pw[i - 1], 2);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> n;
  string s; cin >> s; m = sz(s);
	dp[0][0] = g[0][0] = 1;
	rep(i, 0, n + 1)
		rep(j, 0, i + 1) {
			inc(dp[i + 1][j + 1], dp[i][j]);
			if (j)
				inc(dp[i + 1][j - 1], dp[i][j]);
			inc(g[i + 1][j + 1], mul(2, g[i][j]));
			inc(g[i + 1][max(0, j - 1)], g[i][j]);		
		}
	int ans = 0;
	rep(pre, 0, n + 1) if (n - pre >= m && (n - pre - m) % 2 == 0)
		inc(ans, mul(g[pre][0], mul(dp[n - pre - 1][m - 1], pw[(n - pre - m) / 2])));
	cout << ans;
	return 0;
}
