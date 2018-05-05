// 强匹配 : 偶数点的一张图，随意等分成两部分，均存在完全匹配；
// 若为强匹配图则返回1, 反之 -1
// time : $O(n ^ 3 / 64)$
const int N = 1e2 + 7;
int n, m;
bitset<N> g[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) g[i][i] = 1;
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b), a--, b--;
		g[a][b] = g[b][a] = 1;
	}
	rep(i, 0, n) {
		int ban = 0; rep(j, 0, n) if ((g[i] | g[j]) == g[i]) ban++;
		ban = min(ban, n / 2) - 1;
		int cnt = g[i].count();
		if (cnt - min(cnt, n / 2) - ban <= 0) return 0 * puts("-1");
	} 
	return 0 * puts("1");
}
