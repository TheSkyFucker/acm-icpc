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
const int N = 1e5 + 8, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int a[N], n, q, pw[N];
void solve() {
	cin >> n >> q;
	rep(i, 1, n + 1) {
		cin >> a[i]; a[i] = a[i] & 1;
	}
	rep(i, 1, n + 1) a[i] += a[i - 1];
	rep(i, 0, q) {
		int l, r, t;
		cin >> l >> r >> t;
		int cnt = a[r] - a[l - 1];
		int ans = t == 1 ? add(pw[cnt], MOD - 1) : add(pw[r - l + 1], MOD - pw[cnt]);
		cout << ans << endl;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	pw[0] = 1; rep(i, 1, N) pw[i] = add(pw[i - 1], pw[i - 1]);
	int tcas; cin >> tcas;
	rep(cas, 0, tcas) {
		solve();
	}
	return 0;
}
