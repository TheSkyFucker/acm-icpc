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
const int N = 5e3 + 7, MOD = 1e9 + 7;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int n, a[N], cnt[N], dn[2][N], up[2][N], temp[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	cnt[0] = 1; rep(i, 1, n) cnt[i] = mul(cnt[i - 1], a[i - 1]);
	rep(i, 0, n) dn[0][i] = 1;
	int inv2 = 500000004;
	for (int k = 0, ne = 0, od = 1; k < 2 * n - 2; k++) {
		ne ^= 1, od ^= 1;
		rep(i, 0, n) dn[ne][i] = mul(dn[od][i + 1], a[i]);
		rep(i, 1, n) up[ne][i] = add(up[od][i - 1], add(dn[od][i - 1], MOD - temp[i]));
		copy(dn[od], dn[od] + n, temp);
		int ans = 0;
		rep(i, 0, n) ans = add(ans, mul(add(up[ne][i], dn[ne][i]), cnt[i]));
		printf("%d%c", mul(ans, inv2), " \n"[k == 2 * n - 1]);
	}
	return 0;
}
