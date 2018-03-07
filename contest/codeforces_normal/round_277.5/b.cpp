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
int nx, ny, a[N], b[N];
struct Hug {
	static const int N = ::N;
	vi G[N];
	bool vis[N];
	int par[N], nx, ny;
	void init(int _nx, int _ny) {
		nx = _nx, ny = _ny;
		rep(i, 1, nx + 1) G[i].clear();
	}
	bool find(int u) {
		rep(_v, 0, sz(G[u])) {
			int v = G[u][_v]; if (vis[v]) continue;
			for (vis[v] = true; !~par[v] || find(par[v]); ) return par[v] = u, true;
		}
		return false;
	}
	int work() {
		int ret = 0;
		rep(i, 1, ny + 1) par[i] = -1;
		rep(i, 1, nx + 1) {
			rep(j, 1, ny + 1) vis[j] = false;
			if (find(i)) ret++;
		}
		return ret;
	}
} hug;
int main() {
	scanf("%d", &nx);
	rep(i, 1, nx + 1) scanf("%d", a + i);
	scanf("%d", &ny);
	rep(i, 1, ny + 1) scanf("%d", b + i);
	hug.init(nx, ny);
	rep(i, 1, nx + 1) {
		rep(j, 1, ny + 1) {
			if (abs(a[i] - b[j]) <= 1) {
				hug.G[i].pb(j);
			}
		}
	}
	printf("%d", hug.work());
    
	return 0;
}
