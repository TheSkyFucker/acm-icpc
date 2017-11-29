//g[i][i] should be 0
//index [0..N)
typedef unsigned long long T;
struct BK {
	static const int N = 100; T g[N];
	inline int ctz(T s){ return s ? __builtin_ctzll(s) : 64;}
	int n, ans;
	void gao(T cur, T can, T ban){
		if (!can && !ban) { ans = max(ans, __builtin_popcountll(cur)); return; }
		if (!can) return;
		int piv = ctz(can | ban), ret = 0;
		T z = can & ~g[piv];
		for(int u = ctz(z); u < n; u += ctz(z >> (u + 1)) + 1) {
			gao(cur | (1ull << u), can & g[u], ban & g[u]);
			can ^= 1ull << u, ban |= 1ull << u;
		}
	}
	int run(int n) {
		this->n = n; gao(ans = 0, (1ull << n) - 1, 0);
		return ans;
	}
}	bk;
