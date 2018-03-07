#include<bits/stdc++.h>
using namespace std;
typedef long double db;
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
const int N = 1e3 + 7;
int n, L, x[N], b[N], pre[N];
db dp[N];
db myfabs(db d) { return d > 0. ? d : -d; }
int main() {
	scanf("%d%d", &n, &L);
	rep(i, 1, n + 1) scanf("%d%d", x + i, b + i);
	db l = 0., r = 0.;
	rep(i, 1, n + 1) {
		r += sqrt(myfabs((db)x[i] - x[i - 1] - L));
		l += b[i];
	}
	r /= l; l = 0.;
	rep(i, 0, 100) {
		if (r - l < 1e-13) break;
		db m = (l + r) / 2.;
		rep(i, 1, n + 1) {
			rep(j, 0, i) {
				db tmp = sqrt(myfabs((db)x[i] - x[j] - L)) - m * b[i] + dp[j];
				if (!j || dp[i] > tmp) {
					dp[i] = tmp;
					pre[i] = j;
				}
			}
		}
		if (dp[n] < 1e-13) r = m;
		else l = m;
	}
	vi v;
	for (int u = n; u; u = pre[u]) v.pb(u);
	per(i, 0, sz(v)) printf("%d%c", v[i], " \n"[i == 0]);
	return 0;
}
