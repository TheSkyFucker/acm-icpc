#include <bits/stdc++.h>
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
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"

//-----
int a[10], d;
ll f() {
	ll ret = a[0] * 7ll;
	rep(i, 0, 3) ret += a[i] * 1ll * a[i];
	return ret;
}
void gao() {
	int p = 0;
	while (p < 2 && a[p + 1] == a[p]) p++;
	a[p]++;
}
ll solve() {
	rep(i, 0, 3) cin >> a[i]; cin >> d;
	sort(a, a + 3);
	ll ret = 0;
	rep(i, 0, min(d, 2000000) + 1) {
		if (i) gao();
		a[2] += d - i;
		ret = max(ret, f());
		a[2] -= d - i;
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	rep(cas, 0, tcas) cout << solve() << endl;

	return 0;
}
