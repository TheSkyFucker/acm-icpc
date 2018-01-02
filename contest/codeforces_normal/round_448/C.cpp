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
vi pri;
const int N = 71, B = 19;
const int MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int pw[100007];
int n, v[N], cnt[N];
int f[N][1 << B];
void solve() {
	fill_n(cnt, N, 0);
	rep(i, 0, n) {
		int d; scanf("%d", &d);
		cnt[d]++;
	}
	int lim = 1 << B;
	fill_n(f[1], lim, 0); f[0][0] = 1;
	rep(i, 1, 71) {
		rep(j, 0, lim) {
			if (cnt[i] == 0) { f[i][j] = f[i - 1][j]; continue; }
			f[i][j] = add(mul(f[i - 1][j], pw[cnt[i] - 1]), mul(f[i - 1][j ^ v[i]], pw[cnt[i] - 1]));
		}
	}
	printf("%d\n", add(f[70][0], MOD - 1));
}			
int main() {
	pw[0] = 1; rep(i, 1, 100005) pw[i] = add(pw[i - 1], pw[i - 1]);
	rep(i, 2, 71) {
		bool ok = true;
		for (int j = 2; j * j <= i; j++) if (i % j == 0) ok = false;
		if (ok) pri.pb(i);
	}
	rep(i, 2, 71) {
		rep(p, 0, sz(pri)) if (i % pri[p] == 0) {
			v[i] = v[i / pri[p]] ^ (1 << p);
		}
	}
	while (~scanf("%d", &n)) solve();
	return 0;
}
