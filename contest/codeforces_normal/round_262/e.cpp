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
int n, r;
pair<int, pii> dp[10][10 * 30 * 2][10 * 30 * 2];
int main() {
	scanf("%d%d", &n, &r);
	memset(dp, -1, sizeof(dp));
	const int B = n * r;
	dp[0][B][B].fi = 0;
	rep(i, 0, n) {
		rep(sx, 0, B << 1 | 1) {
			rep(sy, 0, B << 1 | 1) if (~dp[i][sx][sy].fi) {
				int y = 0;
				per(x, 0, r + 1) {
					while ((y + 1) * (y + 1) + x * x <= r * r) y++;
					for (int dx = -1; dx <= 1; dx += 2) 
						for (int dy = -1; dy <= 1; dy += 2) {
							pair<int, pii> &d1 = dp[i + 1][sx + x * dx][sy + y * dy];
							d1 = max(d1, {dp[i][sx][sy].fi + x * x + y * y, {x * dx, y * dy}});
						}
				}
			}
		}
	}
	pair<int, pii> ans = {-1, {0, 0}};
	rep(sx, 0, B << 1 | 1) rep(sy, 0, B << 1 | 1) {
		pair<int, pii> tmp = dp[n][sx][sy];
		tmp.fi = tmp.fi * n - (sx - B) * (sx - B) - (sy - B) * (sy - B);
		tmp.se = {sx, sy};
		ans = max(ans, tmp);
	}
	printf("%d\n", ans.fi);
	vector<pii> v;
	per(i, 1, n + 1) {
		v.pb(dp[i][ans.se.fi][ans.se.se].se);
		ans.se.fi -= v.back().fi;
		ans.se.se -= v.back().se;
	}
	//printf("%d\n", sz(v));
	rep(i, 0, sz(v)) printf("%d %d\n", v[i].fi, v[i].se);
	return 0;
}
