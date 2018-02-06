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
const int N = 5e3 + 7;
int n, c[N];
ll dp[2][N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", c + i);
	vi v(c, c + n); sort(all(v));
	rep(i, 0, n) dp[0][i] = abs(c[0] - v[i]);
	int cur = 0, pre = 1;
	rep(i, 1, n) {
		cur = cur ^ 1;
		pre = pre ^ 1;
		rep(j, 0, n) {
			if (j == 0) dp[cur][j] = dp[pre][j] + abs(c[i] - v[j]);
			else dp[cur][j] = min(dp[cur][j - 1] - abs(c[i] - v[j - 1]), dp[pre][j]) + abs(c[i] - v[j]);
		}
	}
	printf("%lld\n", *min_element(dp[cur], dp[cur] + n));
	return 0;
}
