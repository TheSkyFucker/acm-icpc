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
const int N = 1e2 + 7;
int n, m, k, a[N][N];
int cnt(int xl, int yl, int xr, int yr) {
	return a[xr][yr] - a[xl - 1][yr] - a[xr][yl - 1] + a[xl - 1][yl - 1];
}
void solve() {
	cin >> n >> m >> k;
	rep(i, 1, n + 1) rep(j, 1, m + 1) {
		cin >> a[i][j];
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}
	int ans = 0;
	rep(i1, 1, n + 1) rep(j1, 1, m + 1) {
		int j2 = m;
		rep(i2, i1, n + 1) {
			while (j2 >= j1 && cnt(i1, j1, i2, j2) > k) j2--;
			if (j2 < j1) break;
			ans = max(ans, (i2 - i1 + 1) * (j2 - j1 + 1));
		}
	}
	cout << ans << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	rep(cas, 0, tcas) solve();
	return 0;
}
