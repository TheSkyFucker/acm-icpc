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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
ll n, m, k;
const int MOD = 1e9 + 7;
int mul(int a, int b) { return 1ll * a * b % MOD; }
int qpow(int a, ll b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}
void solve() {
	if (k == - 1 && (n & 1) != (m & 1)) { puts("0"); return; }
	n = (n - 1) % (MOD - 1);
	m = (m - 1) % (MOD - 1);
	printf("%d\n", qpow(2, n * m % (MOD - 1)));
}
int main() {
	while (~scanf("%lld%lld%lld", &n, &m, &k)) solve();

	return 0;
}
