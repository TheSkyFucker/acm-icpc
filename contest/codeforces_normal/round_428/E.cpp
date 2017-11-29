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
//g[i][i] should be 0
//index [0..N)
//O(n ^ 3)
typedef unsigned long long T;
struct BK {
	static const int N = 100; T g[N];
	inline int ctz(T s){ return s ? __builtin_ctzll(s) : 64;}
	int n, ans;
	void ini(int _n) { per(i, 0, n = _n) g[i] = (1ull << n) - 1 - (1ull << i); }
	void gao(T cur, T can, T ban) {
		if (!can && !ban) { ans = max(ans, __builtin_popcountll(cur)); return; }
		if (!can) return;
		int piv = ctz(can | ban), ret = 0;
		T z = can & ~g[piv];
		for(int u = ctz(z); u < n; u += ctz(z >> (u + 1)) + 1) {
			gao(cur | (1ull << u), can & g[u], ban & g[u]);
			can ^= 1ull << u, ban |= 1ull << u;
		}
	}
	int run() { gao(ans = 0, (1ull << n) - 1, 0); return ans; }
}	bk;

int n, k;
void solve() {
	bk.ini(n);
	rep(i, 0, n) rep(j, 0, n) {
		int c; scanf("%d", &c);
		if (i != j && c == 0) bk.g[i] ^= 1ull << j;
	}
	int mx = bk.run();
	printf("%.10f\n", 0.5 * k * k * (mx - 1) / mx);
}

int main() {
	while (~scanf("%d%d", &n, &k)) solve();
	return 0;
}
