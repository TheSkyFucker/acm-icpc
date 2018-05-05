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
int nl, nr, yl, yr;
int main() {
	scanf("%d%d", &nl, &nr);
	scanf("%d", &yl);
	vector<pair<int, pair<char, int> > > v;
	rep(i, 0, nl) {
		int x, y; scanf("%d%d", &x, &y);
		v.pb({x, {'l', y}});
	}
	scanf("%d", &yr);
	rep(i, 0, nr) {
		int x, y; scanf("%d%d", &x, &y);
		v.pb({x, {'r', y}});
	}
	sort(all(v));
	ll ans_k = 0, ans_w = 0, tmp = 0;
	bool beg = true;
	int pre = 0;
	rep(i, 0, sz(v)) {
		ll dx = v[i].fi - pre; pre = v[i].fi;
		if (yr > yl) {
			if (!beg) tmp += 1ll * (yr - yl) * dx;
		}
		else {
			beg = false;
			if (tmp) {
				ans_k++;
				ans_w += tmp;
				tmp = 0;
			}
		}
//		de(dx); dd(yl); dd(yr); de(tmp);
		if (v[i].se.fi == 'l') yl = v[i].se.se;
		else yr = v[i].se.se;
	}
	if (yr < yl && tmp) {
		ans_k++;
		ans_w += tmp;
		tmp = 0;
	}
	printf("%lld %lld", ans_k, ans_w);

	return 0;
}
