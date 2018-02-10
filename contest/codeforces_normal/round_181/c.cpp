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
//#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e6 + 7, MOD = 1e9 + 7;
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
int n, a, b, pw[N], npw[N];
int C(int a, int b) { return mul(pw[a], mul(npw[a - b], npw[b])); }
bool ok(int n) {
	while (n) {
		if (n % 10 != a && n % 10 != b) return false;
		n /= 10;
	}
	return true;
}

int main() {
  pw[0] = 1; rep(i, 1, N) pw[i] = mul(pw[i - 1], i);
  rep(i, 0, N) npw[i] = qpow(pw[i], MOD - 2);
//	rep(i, 0, 10) rep(j, 0, i + 1) printf("%d%c", C(i, j), " \n"[j == i]);
	scanf("%d%d%d", &a, &b, &n);
	int ans = 0;
	rep(na, 0, n + 1) {
		int nb = n - na;
		if (ok(na * a + nb * b)) {
			//dd(na); dd(nb); de(na * a + nb * b);
			ans = add(ans, C(n, na));
		}
	}
	printf("%d\n", ans);
	return 0;
}
