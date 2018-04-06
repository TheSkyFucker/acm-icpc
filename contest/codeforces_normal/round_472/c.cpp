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
const int N = 1e5 + 7;
int n, m[N], dp[N];
int main() {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", m + i);
    dp[n] = 0;
    per(i, 0, n) dp[i] = max(m[i], dp[i + 1] - 1);
	rep(i, 1, n) dp[i] = max(dp[i], dp[i - 1]);
	ll ans = 0;
	rep(i, 0, n) ans += dp[i] - m[i];
	cout << ans;
	return 0;
}
