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
const int N = 1e5 + 7;
int n, emp;
int use[N];
vector<pii> v[2], u[2];
void solve() {
	rep(i, 0, 2) v[i].clear();
	rep(i, 0, n) {
		int t, p; scanf("%d%d", &t, &p); t--;
		v[t].pb(mp(p, i + 1));
	}
	rep(i, 0, 2) sort(all(v[i]));
	rep(i, 0, 2) u[i].clear();
	int ans = 0;
	per(i, 0, sz(v[0])) if (emp) {
		emp--;
		ans += v[0][i].fi;
		u[0].pb(v[0][i]);
	}
	per(i, 0, sz(v[1])) if (sz(u[0]) >= 2 - emp) {
		int ned = 0; rep(j, 0, 2 - emp) ned += u[0][sz(u[0]) - 1 - j].fi;
		if (ned < v[1][i].fi) {
			ans += v[1][i].fi - ned;
			rep(j, 0, 2 - emp) u[0].pop_back();
			emp += max(0, 2 - emp) - 2;
			u[1].pb(v[1][i]);
		}
	}
	printf("%d\n", ans);
	fill_n(use + 1, n, 0);
	rep(i, 0, 2) for (auto e : u[i]) use[e.se] = 1;
	rep(i, 1, n + 1) if (use[i]) printf("%d ", i);
}

int main() {
	while (~scanf("%d%d", &n, &emp)) solve();

	return 0;
}