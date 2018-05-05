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
const int N = 1e3 + 7;
int n, m, q;
struct UF {
	static const int N = ::N * ::N;
	int fa[N];
	void ini() { rep(i, 0, N) fa[i] = i; }
	int getf(int d) { return fa[d] == d ? d : fa[d] = getf(fa[d]); }
	bool comb(int a, int b) {
		if ((a = getf(a)) == (b = getf(b))) return false;
		fa[a] = b;
		return true;
	}
}	uf;
int getid(int x, int y) { x--; y--; return x * m + y; }

int nxt[N][N];
vi g[N * 10];
int res[N * 10];

int ans = 0;
void id2xy(int id, int &x, int &y) {
	x = id / m;
	y = id % m;
	x++; y++;
}
const int G[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok[N][N], use[N][N];
void gao(int id) {
	int x, y; id2xy(id, x, y);
	ok[x][y] = true;
	//dd(x); dd(y);
	ans++;
	rep(i, 0, 4) {
		int nx = x + G[i][0];
		int ny = y + G[i][1];
		if (!ok[nx][ny]) continue;
		ans -= uf.comb(id, getid(nx, ny));
	}
	//de(ans);
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  rep(i, 1, n + 1) rep(j, 0, m + 1) nxt[i][j] = j + 1;
  uf.ini();
  rep(i, 0, q) {
		int xl, yl, xr, yr; scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
		rep(x, xl, xr + 1) {
			for (int y = 0, py = 0; y <= m; y = nxt[x][y]) {
				if (y > yr) break;
				if (y >= yl) { g[i].pb(getid(x, y)); use[x][y] = true; nxt[x][py] = nxt[x][y]; }
				else py = y;
			}
		}
	}
	//int _x, _y; id2xy(10, _x, _y);
	//rep(i, 1, n + 1) rep(j, 1, m + 1) printf("%d%c", use[i][j], " \n"[j == m]);
	rep(i, 1, n + 1) rep(j, 1, m + 1) if (!use[i][j]) gao(getid(i, j));
	res[q - 1] = ans;
	per(i, 1, q) {
		for (auto id : g[i]) gao(id);
		res[i - 1] = ans;
	}
	rep(i, 0, q) printf("%d\n", res[i]);
	return 0;
}
