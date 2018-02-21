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
const int MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}
int C(ll a, ll b) {
	if (a < b) return 0;
	int fz = 1, fm = 1;
	rep(i, 0, b) fz = mul(fz, (a - i) % MOD);
	rep(i, 0, b) fm = mul(fm, (1 + i));
	return mul(qpow(fm, MOD - 2), fz);
}
const int N = 1e2 + 7;
int n;
ll s, f[N];
int main() {
  scanf("%d%lld", &n, &s);
  rep(i, 0, n) scanf("%lld", f + i);
  int ans = 0;
  rep(i, 0, pw(n)) {
  	ll ned = s;
  	rep(j, 0, n) if (i & pw(j)) ned -= f[j] + 1;
  	ans = add(ans, add(MOD, (__builtin_popcount(i) & 1 ? -1 : 1) * C(ned + n - 1, n - 1)));
	}
	printf("%d", ans);
	return 0;
}
