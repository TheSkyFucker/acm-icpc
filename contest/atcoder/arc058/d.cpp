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
const int N = 2e5 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return a * 1ll * b % MOD; }
int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}
int jc[N], ijc[N];
void pre() {
	jc[0] = 1; 
	rep(i, 1, N) jc[i] = mul(jc[i - 1], i);
	ijc[N - 1] = qpow(jc[N - 1], MOD - 2); 
	per(i, 0, N - 1) ijc[i] = mul(ijc[i + 1], i + 1);
}
int C(int n, int m) {
	return mul(jc[n], mul(ijc[n - m], ijc[m]));
}
int gao(int n, int m) { return C(n + m - 2, n - 1); }
int h, w, a, b;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	pre();
	//rep(i, 0, 10) rep(j, 0, i + 1) cout << C(i, j) << " \n"[j == i];
	cin >> h >> w >> a >> b;
	int ans = 0;
	rep(i, b + 1, w + 1)
		ans = add(ans, mul(gao(h - a, i), gao(a, w - i + 1)));
	cout << ans;
	return 0;
}
