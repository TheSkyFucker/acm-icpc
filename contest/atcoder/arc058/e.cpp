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
const int N = 40 + 7, MOD = 1e9 + 7;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int n, x, y, z, dp[N][pw(5)][pw(7)][pw(4)], pw10[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	pw10[0] = 1; rep(i, 1, N) pw10[i] = mul(pw10[i - 1], 10);
	cin >> n >> x >> y >> z;
	dp[0][0][0][0] = 1;
	int ans = 0;
	rep(i, 0, n) {
		rep(mx, 0, pw(x)) {
			rep(my, 0, pw(y)) {
				rep(mz, 0, pw(z - 1)) {
					int d = dp[i][mx][my][mz]; if (!d) continue;
					rep(j, 1, 11) {
						int zx = 1, zy = mx >> (x - 1) & 1, zz = my >> (y - 1) & 1;
						int nmx = (mx << j | (zx << (j - 1))) & (pw(x) - 1);
						int nmy = (my << j | (zy << (j - 1))) & (pw(y) - 1);
						int nmz = (mz << j | (zz << (j - 1))) & (pw(z) - 1);
						if (nmz >> (z - 1) & 1)
							inc(ans, mul(d, pw10[n - i - 1]));
						else
							inc(dp[i + 1][nmx][nmy][nmz], d);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
