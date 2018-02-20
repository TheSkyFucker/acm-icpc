#include<bits/stdc++.h>
using namespace std;
typedef double db;
#define pw(x) (1ll << (x))
#define rep(i,l,r) for(int i=(l);i<(r);++i)

int x, n, p;
db dp[210][pw(8)][2][260];
int main() {
	scanf("%d%d%d", &x, &n, &p);
	db pro = p / 100.;
	rep(j, 0, pw(8)) rep(k, 0, 2) rep(l, 0, 260)
		dp[0][j][k][l] = j ? __builtin_ctz(j) : 8 + l * !k;
	rep(i, 1, n + 1) rep(j, 0, pw(8)) rep(k, 0, 2)
		rep(l, 0, 250) {
			db &d = dp[i][j][k][l];
			int hi = j >> 7 & 1;
			d += pro * dp[i - 1][(j << 1) & (pw(8) - 1)][hi][hi == k ? l + 1 : 1];
			d += (1. - pro) * ( j + 1 < pw(8)
					? dp[i - 1][j + 1][k][l]
					: dp[i - 1][0][!k][k ? l : 1]);
		}
	printf("%.12f\n", dp[n][x & (pw(8) - 1)][x >> 8 & 1][__builtin_ctz((x >> 8) + (x >> 8 & 1)) % 32]);
	return 0;
}
