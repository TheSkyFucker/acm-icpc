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
const int N = 2e1 + 7;
// i-th(0..n-1) element is k(0..3) and current is l(0up1down), already j(0..t) mountain
int n, t;
ll dp[N][N][4][2];

int main() {
	scanf("%d%d", &n, &t);
	rep(k, 0, 4) dp[0][0][k][0] = dp[0][0][k][1] = 1;
	rep(i, 1, n) {
		rep(j, 0, t + 1) {
			rep(k, 0, 4) {
				//dp[i][j][k][0]
				rep(k2, k + 1, 4) dp[i][j][k][0] += dp[i - 1][j][k2][0];
				if (j >= 1 && i > 1) 
					rep(k2, k + 1, 4) dp[i][j][k][0] += dp[i - 1][j - 1][k2][1];
				//dp[i][j][k][1]
				rep(k2, 0, k) dp[i][j][k][1] += dp[i - 1][j][k2][1];
				if (j >= 1)
					rep(k2, 0, k) dp[i][j][k][1] += dp[i - 1][j][k2][0];
			}
		}
	}
	//de(dp[3][0][0][1]);
	ll ans = 0;
	rep(k, 0, 4)  ans += dp[n - 1][t][k][0];
	printf("%lld\n", ans);
	return 0;
}
