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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int mul(int a, int b) { return 1ll * a * b % MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}
char stra[N], strb[N]; 
int n, cnt[30];
int pw[N], inv_pw[N], inv[N], tmp;

int dfs(int p, bool up, bool dn) {
	if (p >= n) return !up && !dn;
	if (!up && !dn) return mul(pw[n - p], tmp);
	int lim = up ? strb[p] - 'a' : 'z' - 'a';
	int beg = dn ? stra[p] - 'a' : 'a' - 'a';
	int ret = 0;
//	dd(up); dd(dn); dd(beg); de(lim);
	rep(i, beg, lim + 1) if (cnt[i]) {
		tmp = mul(tmp, cnt[i]--);
		ret = add(ret, dfs(p + 1, up && i == lim, dn && i == beg));
		tmp = mul(tmp, inv[++cnt[i]]);
	}
	return ret;
}
void solve() {
	fill_n(cnt, 26, 0);
	n = strlen(stra);
	rep(i, 0, n) cnt[stra[i] - 'a']++;
	tmp = 1;
	rep(i, 0, 26) tmp = mul(tmp, inv_pw[cnt[i]]);
	printf("%d\n", dfs(0, true, true));
}
int main() {
	pw[0] = 1; 
	rep(i, 1, N) inv[i] = qpow(i, MOD - 2);
	rep(i, 1, N) pw[i] = mul(pw[i - 1], i);
	rep(i, 0 ,N) inv_pw[i] = qpow(pw[i], MOD - 2);
	while (~scanf(" %s %s", stra, strb)) solve();

	return 0;
}
