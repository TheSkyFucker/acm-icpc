#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
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

///----------------------------------------------
const int N = 1e5 + 7;
int n;

int qpow(int a, int b, int MOD) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = 1ll * ret * a % MOD;
		a = 1ll * a * a % MOD;
	}
	return ret;
}

void solve() {
	scanf("%d", &n);
	db ans = 0.;
	rep(k, 0, n) {
		int md1 = 8 * k + 1, md2 = 8 * k + 4, md3 = 8 * k + 5, md4 = 8 * k + 6;
		ans += (db)(4 * qpow(16, n - 1 - k, md1) % md1) / md1;
		ans -= (db)(2 * qpow(16, n - 1 - k, md2) % md2) / md2;
		ans -= (db)(1 * qpow(16, n - 1 - k, md3) % md3) / md3;
		ans -= (db)(1 * qpow(16, n - 1 - k, md4) % md4) / md4;
		//de(ans);
	}
	db tmp = 1.;
	rep(k, n, n + 1000) {
		tmp /= 16;
		ans += tmp * (4. / (8 * k + 1) - 2. / (8 * k + 4) - 1. / (8 * k + 5) - 1. / (8 * k + 6));
	}
	ans += 100. * n;
	int ret = (int)((ans - (ll)ans) * 16);
	printf("%d %c\n", n, ret <= 9 ? ret + '0' : ret - 10 + 'A');
}

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 0, tcase) {
		printf("Case #%d: ", icase + 1);
		solve();
	}
	return 0;
}

