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

struct UF {
	static const int N = 1e3 + 7;
	int far[N];
	void ini(int n = N) { rep(i, 0, n) far[i] = i; }
	int getf(int d) { return far[d] == d ? d : far[d] = getf(far[d]); }
	int same(int a, int b) { return getf(a) == getf(b); }
	void comb(int a, int b) {
		if (same(a, b)) return;
		else a = far[a], b = far[b];
		far[a] = b;
	}
}	uf0, uf1;

const int N = 2e5 + 7;
int n, m;
int a[N], b[N];
char c[N];
int main() {
	scanf("%d%d", &n, &m);
	if (n % 2 == 0) return 0 * puts("-1");
	rep(i, 0, m) scanf("%d%d %c", &a[i], &b[i], &c[i]), a[i]--, b[i]--;
  uf0.ini();
  uf1.ini();
  rep(i, 0, m) if (c[i] == 'S') uf0.comb(a[i], b[i]);
	int ned = (n - 1) / 2;
	vi ans;
	rep(i, 0, m) if (c[i] == 'M' && !uf0.same(a[i], b[i])) {
		uf0.comb(a[i], b[i]);
		uf1.comb(a[i], b[i]);
		ans.pb(i);
		ned--;
	}
	rep(i, 0, m) if (c[i] == 'M' && !uf1.same(a[i], b[i])) {
		if (ned <= 0) break; else ned--;
		uf1.comb(a[i], b[i]);
		ans.pb(i);
	}
	if (ned != 0) return 0 * puts("-1");
	rep(i, 0, n) if (!uf0.same(0, i)) return 0 * puts("-1");
	rep(i, 0, m) if (c[i] == 'S' && !uf1.same(a[i], b[i])) {
		uf1.comb(a[i], b[i]);
		ans.pb(i);
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
	return 0;
}
