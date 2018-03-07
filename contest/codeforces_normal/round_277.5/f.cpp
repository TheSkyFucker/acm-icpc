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
const int N = 5e2 + 7;
int MOD, cnt[N], n, m;
char str[N];
int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int _dp[N][N];
int dp(int ct1, int ct2) {
	int &ret = _dp[ct1][ct2];
	if (~ret) return ret;
	else ret = 0;
	if (!ct1 && !ct2) return ret = 1;
	if (ct1 >= 2) ret = add(ret, mul((1ll * ct1 * (ct1 - 1) / 2) % MOD, dp(ct1 - 2, ct2)));
	if (ct2 >= 2) ret = add(ret, mul((1ll * ct2 * (ct2 - 1) / 2) % MOD, dp(ct1 + 2, ct2 - 2)));
	if (ct1 && ct2) ret = add(ret, mul(ct1, mul(ct2, dp(ct1, ct2 - 1))));
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &MOD);
	memset(_dp, -1, sizeof(_dp));
	rep(i, 0, m) {
		scanf(" %s", str);
		rep(j, 0, n) cnt[j] += str[j] - '0';
	}
	int ct1 = 0, ct2 = 0;
	rep(i, 0, n) if (cnt[i] == 0) ct2++; else if (cnt[i] == 1) ct1++; 
	printf("%d", dp(ct1, ct2));
	return 0;
}
