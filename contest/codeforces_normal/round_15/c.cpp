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
ll f(ll n) { return n & 1 ? f(n - 1) ^ n : n + (n >> 1 & 1); }
ll f(ll l, ll r) { return f(r) ^ (l > 0 ? f(l - 1) : 0); }
int main() {
	int n; scanf("%d", &n);
	ll ans = 0;
	rep(i, 0, n) {
		ll x, m; scanf("%lld%lld", &x, &m);
		ans ^= f(x, x + m - 1);
	}
	puts(ans ? "tolik" : "bolik");
	return 0;
}
