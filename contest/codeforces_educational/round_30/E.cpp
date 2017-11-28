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
const int N = 3e3 + 7;
int n; pii a[N], mx[N][N];
int lv[N];
void solve() {
	rep(i, 1, n + 1) scanf("%d", &a[i].fi), a[i].se = i; a[n + 1].fi = 0;
	sort(a + 1, a + 1 + n); reverse(a + 1, a + 1 + n);
	rep(i, 1, n + 1) mx[i][i] = {a[i].fi - a[i + 1].fi, i};
	rep(l, 2, n + 1) rep(i, 1, n + 1) {
		int j = i + l - 1; if (j > n) break;
		mx[i][j] = max(mx[i + 1][j], {a[i].fi - a[i + 1].fi, i});
	}
	pair<pair<int, pii>, pair<int, pii> > ans; ans.fi.fi = -1;
	rep(i1, 1, n + 1) rep(i2, i1 + 1, n + 1) {
		if (min(i2 - i1, i1) * 2 < max(i2 - i1, i1)) continue;
		int l = i2 + max(1, (max(i1, i2 - i1) + 1) / 2);
		int r = i2 + min(n - i2, min(i1, i2 - i1) * 2);
		if (l > r) continue;
		int i3 = mx[l][r].se;
		ans = max(ans, { { mx[i1][i1].fi, {mx[i2][i2].fi, mx[i3][i3].fi} }, { i1, {i2, i3} } });
	}
	rep(i, 1, ans.se.fi + 1) lv[a[i].se] = 1;
	rep(i, ans.se.fi + 1, ans.se.se.fi + 1) lv[a[i].se] = 2;
	rep(i, ans.se.se.fi + 1, ans.se.se.se + 1) lv[a[i].se] = 3;
	rep(i, ans.se.se.se + 1, n + 1) lv[a[i].se] = -1;
	rep(i, 1, n + 1) printf("%d%c", lv[i], " \n"[i == n]);
}

int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
