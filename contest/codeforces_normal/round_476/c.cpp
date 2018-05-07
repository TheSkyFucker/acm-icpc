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
ll mul(ll a, ll b) { return !a || !b ? 0 : a * min(LLONG_MAX / a, b); }
ll add(ll a, ll b) { return a + min(LLONG_MAX - a, b); }
ll n, k, m, d;
int main() {
	scanf("%lld%lld%lld%lld", &n, &k, &m, &d);
	ll ans = -LLONG_MAX;
	rep(t, 0, d) {
		ll mxx = min(m, n / (mul(t, k) + 1));
		if (mul(mxx, add(1, add(k, mul(t, k)))) < n) continue;
		ans = max(ans, (t + 1) * mxx);
	}
	printf("%lld", ans);
	return 0;
}
