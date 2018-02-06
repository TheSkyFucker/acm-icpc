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
int n;
vi chg(int n, int b) {
	vi r;
	while (n) {
		r.pb(n % b);
		n /= b;
	}
	return r;
}
		
int main() {
	scanf("%d", &n);
	int ans = 0;
	rep(i, 2, n) {
		auto v = chg(n, i);
		for(auto e : v) ans += e;
	}
	int tmp = __gcd(ans, n - 2);
	printf("%d/%d\n", ans / tmp, (n - 2) / tmp);
	return 0;
}
