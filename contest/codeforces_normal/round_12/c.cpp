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
const int N = 1e3 + 7;
int n, m, a[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	map<string, int> cnt;
	rep(i, 0, m) {
		string name; cin >> name;
		cnt[name]++;
	}
	vi v;
	for (auto e : cnt) v.pb(e.se);
	sort(all(v));
	ll mi = 0, mx = 0;
	rep(i, 0, sz(v)) {
		mi += 1ll * v[i] * a[sz(v) - 1 - i];
		mx += 1ll * v[i] * a[n - sz(v) + i];
	}
	printf("%lld %lld\n", mi, mx);
	return 0;
}
