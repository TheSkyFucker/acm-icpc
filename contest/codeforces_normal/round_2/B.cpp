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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int n, a[N][N];
pii dp[2][N][N];
int getv(int i, int j, int d) {
	if (a[i][j] == 0) return INF;
	int ret = 0, tmp = a[i][j]; while (tmp % d == 0) ret++, tmp /= d;
	return ret;
}
void gao(int d, pii dp[N][N]) {
	dp[0][0] = mp(getv(0, 0, d), -1);
	rep(i, 0, n) rep(j, 0, n) {
		if (i == 0 && j == 0) continue;
		int vij = getv(i, j, d);
		dp[i][j] = mp(INF, -1);
		if (i - 1 >= 0) dp[i][j] = min(dp[i][j], mp(dp[i - 1][j].fi + vij, 0));
		if (j - 1 >= 0) dp[i][j] = min(dp[i][j], mp(dp[i][j - 1].fi + vij, 1));
	}
}
void solve() {
	int zx = -1, zy = -1;
	rep(i, 0, n) rep(j, 0, n) {
		scanf("%d", &a[i][j]);
		if (!a[i][j]) zx = i, zy = j;
	}
	int ans = INF;
	gao(2, dp[0]); ans = min(ans, dp[0][n - 1][n - 1].fi);
	gao(5, dp[1]); ans = min(ans, dp[1][n - 1][n - 1].fi);
	if (ans > 1 && ~zx) {
		puts("1");
		rep(i, 0, zx) putchar('D');
		rep(i, 0, zy) putchar('R');
		rep(i, zx, n - 1) putchar('D');
		rep(i, zy, n - 1) putchar('R');
		puts("");
		return ;
	}
	printf("%d\n", ans);
	rep(i, 0, 2) if (ans == dp[i][n - 1][n - 1].fi) {
		vector<char> res;
		for (int x = n - 1, y = n - 1; x > 0 || y > 0; ) {
			//dd(x); de(y);
			if (dp[i][x][y].se == 0) x--, res.pb('D');
			else y--, res.pb('R');
		}
		per(j, 0, sz(res)) printf("%c", res[j]); puts("");
		return;
	}

}
	
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}
