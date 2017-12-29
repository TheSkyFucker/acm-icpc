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
const int N = 1e5 + 7;
int n, x, k, a[N];
void solve() {
	map<int, int> M;
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	ll ans = 0;
	per(i, 0, n) {
		int cnt = (a[i] - 1) / x;
		if (M.count(cnt + k)) ans += M[cnt + k];
		M[a[i] / x]++;
	}
	for (int l = 0, r; l < n; l = r) {
		for (r = l; r < n && a[r] == a[l]; r++);
		int tmp = a[l] % x == 0 ? 1 : 0;
		if (tmp == k) ans += 1ll * (r - l + 1) * (r - l) / 2;
	}
	printf("%lld\n", ans);
}
		
int main() {
	while (~scanf("%d%d%d", &n, &x, &k)) solve();

	return 0;
}
