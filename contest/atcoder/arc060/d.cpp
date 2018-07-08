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
ll mul(ll a, ll b) { return a * min(b, LLONG_MAX / a); }
ll f(ll b, ll n) {
	ll r = 0;
	while (n) { r += n % b; n /= b; }
	return r;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, s; cin >> n >> s;
  rep(b, 2, 1000001) if (f(b, n) == s) { cout << b; return 0; }
	per(x, 1, 100000) {
		if ((n + x - s) < 2 || (n + x - s) % x != 0) continue;
		ll b = (n + x - s) / x;
		if (mul(x, b) > n || mul(x + 1, b) <= n) continue;
		cout << b; return 0;
	}
	if (n == s) cout << n + 1;
	else cout << -1;
	return 0;
}
