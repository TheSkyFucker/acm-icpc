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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
const int N = 1e6 + 7;
int a[N], n;

struct Tree {
	static const int N = ::N;
	ll val[N]; int n;
	void ini(int _n) { fill_n(val + 1, n = _n, 0); }
	void add(int p, ll v) { for (; p <= n; p += p & -p) val[p] += v; }
	ll qry(int p) { ll r = 0; for (; p; p -= p & -p) r += val[p]; return r; }
}	tree;

ll dp[N];
void solve() {
	vi v; v.resize(n);
	rep(i, 1, n + 1) scanf("%d", a + i), v[i - 1] = a[i];
	sort(all(v)); v.erase(unique(all(v)), v.end());
	rep(i, 1, n + 1) a[i] = v.end() - lower_bound(all(v), a[i]);
	rep(i, 1, n + 1) dp[i] = 1;
	rep(j, 0, 2) {
		tree.ini(sz(v));
		rep(i, 1, n + 1) {
			ll tmp = dp[i];
			dp[i] = tree.qry(a[i] - 1);
			tree.add(a[i], tmp);
		}
		
	}
	ll ans = 0; rep(i, 1, n + 1) ans += dp[i];
	printf("%lld\n", ans);
}

int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
