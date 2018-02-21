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
const int N = 5001;
int n, m, k, a[N];
ll dp[N][N], s[N];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n + 1) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	per(i, m, n + 1) s[i] -= s[i - m];
	memset(dp, -1, sizeof(dp));
	rep(i, 0, n + 1) dp[i][0] = 0;
	rep(i, m, n + 1) rep(j, 1, k + 1) {
		dp[i][j] = dp[i - 1][j];
		if (~dp[i - m][j - 1])
			dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + s[i]);
	}
	printf("%lld", dp[n][k]);
	return 0;
}
