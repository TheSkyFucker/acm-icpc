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
const int N = 1e2 + 7;
int a[N][N], n, m, k;
int dp[N][N * N];
pii solve() {
	rep(i, 1, n + 1) rep(j, 1, m + 1) scanf("%d", &a[i][j]);
	rep(i, 1, m + 1) rep(j, 1, n * m + 1) dp[i][j] = 0;
	rep(i, 1, m + 1) {
		int cur = 0; rep(j, 1, min(k, n) + 1) cur += a[j][i];
		int ned = 0;
		rep(j, 1, n + 1) {
			int lim = i * n;
			rep(p, ned, lim + 1) dp[i][p] = max(dp[i][p], dp[i - 1][p - ned] + cur);
			cur -= a[j][i]; if (j + k <= n) cur += a[j + k][i];
			if (a[j][i]) ned++;
		}
	}
	pii ret = mp(-1, -1);
	rep(i, 0, n * m + 1) ret = max(ret, {dp[m][i], -i});
	ret.se = -ret.se;
	return ret;
}

int main() {
	while (~scanf("%d%d%d", &n, &m, &k)) {
		pii ans = solve(); 
		printf("%d %d\n", ans.fi, ans.se);
	}
	return 0;
}
