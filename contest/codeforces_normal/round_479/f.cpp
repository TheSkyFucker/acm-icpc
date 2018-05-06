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
const int N = 2e5 + 7;
int n, a[N], dp[N], pre[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	map<int, int> Map;
	int mx = 0;
	rep(i, 0, n) {
		dp[i] = 1;
		pre[i] = -1;
		if (Map.count(a[i] - 1)) {
			int p = Map[a[i] - 1];
			dp[i] = dp[p] + 1;
			pre[i] = p;
		}
		Map[a[i]] = i;
		mx = max(mx, dp[i]);
	}
	rep(i, 0, n) if (dp[i] == mx) {
		vi v;
		for (int j = i; ~j; j = pre[j]) v.pb(j);
		assert(sz(v) == mx);
		printf("%d\n", mx);
		per(i, 0, mx) printf("%d%c", v[i] + 1, " \n"[i == 0]);
		return 0;
	}
	return 0;
}
