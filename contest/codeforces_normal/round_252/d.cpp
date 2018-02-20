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
const int N = 3e3 + 7;
int n, m, p[N], col[N];
int dfs(int u, int c) {
	col[u] = c;
	if (!~col[p[u]]) dfs(p[u], c);
}
int redraw() {
	fill_n(col, n, -1);
	int cir = 0;
	rep(i, 0, n) if (!~col[i]) dfs(i, cir++);
	return cir;
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", p + i), p[i]--;
	scanf("%d", &m);
	int cir = redraw();
	int ned = n - cir;
	printf("%d\n", abs(ned - m));
	rep(_, ned, m) {
		redraw();
		rep(i, 1, n) if (col[i] != col[0]) {
			printf("%d %d ", 1, i + 1);
			swap(p[0], p[i]);
			break;
		}
	}
	rep(_, m, ned) {
		redraw();
		int i = 0; while (p[i] == i) i++;
		rep(j, i + 1, n) if (col[j] == col[i]) {
			printf("%d %d ", i + 1, j + 1);
			swap(p[i], p[j]);
			break;
		}
	}
	return 0;
}
