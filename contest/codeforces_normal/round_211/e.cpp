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
const int N = 5e2 + 7;
int n, m, r, a[N][N];
vector<pii> o1, o2;
void geto() {
	int dy = r;
	rep(dx, 0, r + 1) {
		while (dx * dx + dy * dy > r * r) dy--;
		o1.pb({dx, dy});
		if (dx) o1.pb({-dx, dy});
	}
	for (auto p : o1) for (auto v : o1) 
		o2.pb({p.fi + v.fi, - p.se - v.se});
	sort(all(o2));
	vector<pii> ret;
	rep(i, 0, sz(o2)) if (!i || o2[i].fi != o2[i - 1].fi) 
		ret.pb({o2[i].fi, -o2[i].se});
	swap(ret, o2);
}
int dp[N][N], mx[N];
pii rt[N][N];
int main() {
	scanf("%d%d%d", &n, &m, &r);
	rep(i, 0, n) rep(j, 0, m) scanf("%d", &a[i][j]);
	geto();
	rep(i, r, n - r) {
		for (auto v : o1)
			rep(j, -v.se, v.se + 1)
				dp[i][r] += a[i + v.fi][r + j];
		rep(j, r + 1, m - r) {
			dp[i][j] = dp[i][j - 1];
			for (auto v : o1) dp[i][j] += a[i + v.fi][j + v.se] - a[i + v.fi][j - v.se - 1];
		}
	}
	rep(i, r, n - r) {
		per(j, r, m - r) {
			rt[i][j] = rt[i][j + 1];
			if (rt[i][j + 1].fi == dp[i][j]) rt[i][j].se++;
			else if (rt[i][j + 1].fi < dp[i][j]) rt[i][j] = {dp[i][j], 1};
		}
	}
	pair<int, ll> ans = {0, 0};
	rep(i, r, n - r) {
		fill_n(mx, n, 0);
		rep(j, r, m - r) {
			rep(k, 0, i) mx[k] = max(mx[k], j);
			rep(k, i, n) mx[k] = max(mx[k], j + 1);
			for (auto v : o2)
				if (i + v.fi >= 0 && i + v.fi < n)
					mx[i + v.fi] = max(mx[i + v.fi], j + v.se + 1);
			rep(k, r, n - r) if (mx[k] < m - r) {
				pii tmp = rt[k][mx[k]]; tmp.fi += dp[i][j];
				if (tmp.fi == ans.fi) ans.se += tmp.se;
				else if (tmp.fi > ans.fi) ans = tmp;
			}
		}
	}
	printf("%d %lld", ans.fi, ans.se);
	return 0;
}
