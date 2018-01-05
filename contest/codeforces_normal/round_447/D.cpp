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
const int N = (1 << 21) + 7;
int n, m, l[N];
vi vdep[N];
vector<ll> vsum[N];
ll getv(int p, int h) {
	ll cnt = upper_bound(all(vdep[p]), h) - vdep[p].begin();
	return cnt * h - vsum[p][cnt - 1];
}
void solve() {
	rep(i, 2, n + 1) scanf("%d", l + i);
	per(i, 1, n + 1) {
		vdep[i].pb(0);
		int pl = 0, pr = 0, ls = i << 1, rs = i << 1 | 1;
		while (pl < sz(vdep[ls]) || pr < sz(vdep[rs])) {
			if (pr >= sz(vdep[rs]) || (pl < sz(vdep[ls]) && vdep[ls][pl] + l[ls] < vdep[rs][pr] + l[rs]))
				vdep[i].pb(vdep[ls][pl++] + l[ls]);
			else 
				vdep[i].pb(vdep[rs][pr++] + l[rs]);
		}
		vsum[i].pb(0);
		rep(j, 1, sz(vdep[i])) vsum[i].pb(vsum[i].back() + vdep[i][j]);
	}
	rep(i, 1, m + 1) {
		int a, h; scanf("%d%d", &a ,&h);
		ll ans = getv(a, h);
		for (; a > 1; a >>= 1) {
			h -= l[a]; if (h < 0) break; else ans += h;
			int b = a ^ 1;
			if (b >= 1 && b <= n) {
				int bh = h - l[b];
				if (bh >= 0) ans += getv(b, bh);
			}
		}
		printf("%lld\n", ans);
	}
	rep(i, 1, n + 1) vdep[i].clear(), vsum[i].clear();
}				
		
int main() {
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}
