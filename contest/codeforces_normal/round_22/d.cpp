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
const int N = 1e3 + 8;
int n;
pii p[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		scanf("%d%d", &p[i].fi, &p[i].se);
		if (p[i].fi > p[i].se) swap(p[i].fi, p[i].se);
	}
	sort(p, p + n);
	int mi = pw(30); vi ans;
	rep(i, 0, n) {
		if (p[i].fi > mi) {
			ans.pb(mi);
			mi = pw(30);
		}
		mi = min(mi, p[i].se);
	}
	ans.pb(mi);
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
    
	return 0;
}
