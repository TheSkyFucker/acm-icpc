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
const int N = 2e2 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int dp[N][N];
void pre() {
	dp[0][0] = 1;
	rep(i, 1, 105)
		rep(j, 0, N)
			rep(k, 1, i + 1) if ((j ^ k) < N) {
				dp[i][j] = add(dp[i][j], dp[i - k][j ^ k]);
			}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	pre();
	rep(cas, 0, tcas) {
		int n; cin >> n;
		int ans = 0;
		rep(i, 1, N) ans = add(ans, dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}
