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
const int N = 2e5 + 7;
int n, T; pii a[N];
int main() {
    scanf("%d%d", &n, &T);
	rep(i, 0, n) scanf("%d", &a[i].se);
	rep(i, 0, n) scanf("%d", &a[i].fi), a[i].fi -= T; 
	sort(a, a + n);
    ll sum = 0; rep(i, 0, n) sum += 1ll * a[i].fi * a[i].se;
    db ans = 0; rep(i, 0, n) ans += a[i].se;
    if (sum > 0) {
		per(i, 0, n) {
			ll tmp = 1ll * a[i].fi * a[i].se;
			if (sum - tmp > 0) { sum -= tmp; ans -= a[i].se; continue; }
			ans -= (db)sum / a[i].fi;
			sum = 0;
			break;
		}
	}
	else if (sum < 0) {
		rep(i, 0, n) {
			ll tmp = 1ll * a[i].fi * a[i].se;
			if (sum - tmp < 0) { sum -= tmp; ans -= a[i].se; continue; }
			ans -= (db)sum / a[i].fi;
			sum = 0;
			break;
		}
	}
	printf("%.15f\n", ans);
	return 0;
}
