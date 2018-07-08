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
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"

//-----
const int N = 1e6 + 7, MOD = 1e9 + 7;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int qpow(int a, int b) { int r = 1; for (; b; b >>= 1) { if (b & 1) r = mul(r, a); a = mul(a, a); } return r; }
int n, m, k;
int jc[N], ijc[N], pw3[N];
void ini() {
	jc[0] = 1; rep(i, 1, N) jc[i] = mul(jc[i - 1], i);
	ijc[N - 1] = qpow(jc[N - 1], MOD - 2); per(i, 0, N - 1) ijc[i] = mul(ijc[i + 1], i + 1);
	pw3[0] = 1; rep(i, 1, N) pw3[i] = mul(pw3[i - 1], 3);
}
int C(int a, int b) { return mul(jc[a], mul(ijc[b], ijc[a - b])); }
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ini();//rep(i, 0, 10) rep(j, 0, i + 1) cout << C(i, j) << " \n"[j == i];
	cin >> n >> m >> k;
	int g = 0, inv2 = qpow(2, MOD - 2);
	rep(j, 0, k + 1) inc(g, mul(pw3[k - j], C(j + n - 1, j)));
	int ans = 0;
	rep(i, 0, m + 1) {
		inc(ans, mul(pw3[m - i], mul(C(i + n - 1, i), g)));
		g = mul(g, 3);
		inc(g, MOD - C(i + k + n, i + n));
		g = mul(g, inv2);
	}
	cout << ans;
	return 0;
}
