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
const int N = 1e3 + 7;
int w[N], t[N], n;
int dp[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d%d", &t[i], &w[i]), w[i] += t[i];
	int tot = 1; rep(i, 0, n) tot += t[i];
	rep(i, 0, n) {
		per(j, w[i], tot) dp[j] = max(dp[j], dp[j - w[i]] + t[i]);
	}
	int ans = 0; rep(i, 0, tot) ans = max(ans, dp[i]);
	printf("%d\n", tot - 1 - ans);
    
	return 0;
}
