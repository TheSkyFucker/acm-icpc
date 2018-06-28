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
const int N = 1e3 + 7, MOD = 998244353;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int n, a[N], dp[N], C[N][N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 0, N) C[i][0] = 1;
	rep(i, 0, N) rep(j, 1, i + 1) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	//rep(i, 0, 10) rep(j, 0, i + 1) cout << C[i][j] << " \n"[j == i];
  cin >> n;
  rep(i, 1, n + 1) cin >> a[i];
  rep(i, 1, n + 1)
  	rep(j, 1, i) if (a[j] > 0 && a[j] <= i - j)
			dp[i] = add(dp[i], mul(dp[j - 1] + 1, C[i - j][a[j]]));
	//rep(i, 1, n + 1) de(dp[i]);
	cout << dp[n];
	return 0;
}
