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
int dp[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m; cin >> n >> m;
	vi v(1, 0);
	rep(i, 0, n) {
		int ai; cin >> ai;
		v.pb(ai);
	}
	v.pb(m);
	int ans = 0, can = 0, tmp = 0;
	per(i, 0, sz(v) - 1) dp[i] = dp[i + 1] + ((i & 1) ? v[i + 1] - v[i] : 0);
	rep(i, 0, sz(v) - 1) {
		if (!(i & 1)) tmp += v[i + 1] - v[i];
		else if (v[i + 1] > v[i] + 1) {
			ans = max(ans, tmp + v[i + 1] - v[i] - 1 + dp[i + 1]);
		}
	}
	cout << max(ans, tmp);
	return 0;
}
