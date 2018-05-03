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
int n, a, b;
int main() {
	scanf("%d%d%d", &n, &a, &b);
	map<ll, int> Map;
	map<pii, int> Map2;
	ll ans = 0, cnt0 = 0;
	rep(i, 0, n) {
		int x, vx, vy; scanf("%d%d%d", &x, &vx, &vy);
		ll det = 1ll * a * vx - vy;
		ans += 2 * (Map[det] - Map2[{vx, vy}]);
		Map[det]++;
		Map2[{vx, vy}]++;
	}
	printf("%lld", ans);
	return 0;
}
