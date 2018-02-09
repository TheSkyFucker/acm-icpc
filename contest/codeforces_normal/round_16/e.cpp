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
const int N = 18;
int n;
db a[N][N], dp[pw(N)];

int main() {
  scanf("%d", &n);
  rep(i, 0, n) rep(j, 0, n) scanf("%lf", &a[i][j]);
  dp[pw(n) - 1] = 1.;
  per(i, 0, pw(n)) {
		int b = __builtin_ctz(i);
		int t = __builtin_popcount(i); t = t * (t - 1) / 2;
		rep(j, b, n) if (i & pw(j)) {
			rep(k, j + 1, n) if (i & pw(k)) {
				dp[i ^ pw(k)] += dp[i] * a[j][k] / t;
				dp[i ^ pw(j)] += dp[i] * a[k][j] / t;
			}
		}
	}
	rep(i, 0, n) printf("%.12f%c", dp[pw(i)], " \n"[i == n - 1]);
	return 0;
}
