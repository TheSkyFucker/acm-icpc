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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int inc(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int n, cnt[N], dp[N], po[N];
void solve() {
	fill_n(cnt, N, 0);
	rep(i, 0, n) { int d; scanf("%d", &d); cnt[d]++; }
	int ans = 0;
	per(d, 2, N) {
		int sum = 0; for (int i = d; i < N; i += d) sum += cnt[i]; if (!sum) continue;
		dp[d] = mul(sum, po[sum - 1]);
		for (int i = d + d; i < N; i += d) dp[d] = inc(dp[d], MOD - dp[i]);
		ans = inc(ans, mul(dp[d], d));
	}
	printf("%d\n", ans);
}
int main() {
	po[0] = 1; rep(i, 1, N) po[i] = inc(po[i - 1], po[i - 1]);
	while (~scanf("%d", &n)) solve();
	return 0;
}
