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
const int N = 3e3 + 7;
int n;
pair<int, string> p[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) cin >> p[i].se >> p[i].fi;
	sort(p, p + n);
	vi v;
	rep(i, 0, n) {
		if (p[i].fi > sz(v)) return 0 * puts("-1");
		v.pb(i);
		rep(j, 0, p[i].fi) swap(v[sz(v) - 1 - j], v[sz(v) - 1 - j - 1]);
	}
	rep(i, 0, n) p[v[i]].fi = i + 1;
	rep(i, 0, n) cout << p[i].se << " " << p[i].fi << endl;
	return 0;
}
