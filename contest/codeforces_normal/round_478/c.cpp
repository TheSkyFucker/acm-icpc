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
int n, q;
ll a[N];
int main() {
	scanf("%d%d", &n, &q);
	rep(i, 0, n) scanf("%lld", a + i), a[i] += i ? a[i - 1] : 0;
	ll sumk = 0;
	rep(i, 0, q) {
		ll k; scanf("%lld", &k); sumk += k;
		int p = upper_bound(a, a + n, sumk) - a;
		int ans = n - p;
		if (!ans) { ans = n, sumk = 0; }
		printf("%d\n", ans);
	}

	return 0;
}
