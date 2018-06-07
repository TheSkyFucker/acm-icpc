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
int ans = INT_MAX;
vi v;
int gao(int a, int b) {
	vi v = ::v;
	int ret = 0;
	bool ok = false;
	per(i, 0, sz(v) - 0) if (v[i] == b) {
		rep(j, i, sz(v) - 1) { swap(v[j], v[j + 1]); ret++; }
		ok = true;
		break;
	}
	if (!ok) return INT_MAX;
	ok = false;
	per(i, 0, sz(v) - 1) if (v[i] == a) {
		rep(j, i, sz(v) - 2) { swap(v[j], v[j + 1]); ret++; }
		ok = true;
		break;
	}
	if (!ok) return INT_MAX;
	if (v[0] == 0) {
		rep(i, 0, sz(v) - 2) if (v[i] != 0) return ret + i;
		return INT_MAX;
	}
	else return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n; cin >> n;
	while (n) { v.pb(n % 10); n /= 10; }
	reverse(all(v));
	int ans = INT_MAX;
	ans = min(ans, gao(0, 0)); //de(ans);
	ans = min(ans, gao(2, 5)); //de(ans);
	ans = min(ans, gao(5, 0)); //de(ans);
	ans = min(ans, gao(7, 5)); //de(ans);
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
