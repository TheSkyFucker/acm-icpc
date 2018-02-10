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
const int B = 31, N = 1e3 + 7, MOD = 7340033;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int dp1[B][N << 1], dp2[B][N << 1];
int main() {
	rep(i, 0, B) dp2[i][0] = 1;
	rep(i, 1, B) {
		rep(j, 0, N) rep(k, 0, N) 
			dp1[i][j + k    ] = add(dp1[i][j + k    ], mul(dp2[i - 1][j], dp2[i - 1][k]));
		rep(j, 0, N) rep(k, 0, N)
		  dp2[i][j + k + 1] = add(dp2[i][j + k + 1], mul(dp1[i    ][j], dp1[i    ][k]));
	}
	int t; scanf("%d", &t);
	rep(i, 0, t) {
		int n, m; scanf("%d%d", &n, &m); n++;
		printf("%d\n", dp2[__builtin_ctz(n) - ((n & - n) == n)][m]);
	}
	return 0;
}
