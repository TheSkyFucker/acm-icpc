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
const int N = 50 + 6, B = 2500;
int n, a, x[N];
ll dp[N][N * 100];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> n >> a;
  rep(i, 1, n + 1) cin >> x[i], x[i] -= a;
  dp[0][B + 0] = 1;
  rep(i, 0, n + 1) rep(j, 0, 2 * B) if (dp[i][j]) {
  	dp[i + 1][j + x[i + 1]] += dp[i][j];
  	dp[i + 1][j] += dp[i][j];
	}
	cout << dp[n][B] - 1;
	return 0;
}
