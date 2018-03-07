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
const int N = 1e5 + 7;
int n, qn, a[N];
struct Q { int op, x, v; ll w; } q[N];
struct Fenwick {
	static const int N = ::N << 1;
	ll a[N]; int n;
	void ini(int _n) { n = _n; }
	void add(int p, int v) { for (; p <= n; p += p & -p) a[p] += v; }
	ll qry(int p) { ll r = 0; for (; p; p -= p & -p) r += a[p]; return r; }
}	t1, t2;
vi v;
int h(int d) { return lower_bound(all(v), d) - v.begin() + 1; }
void g(int x, int v) {
	t1.add(h(x), v);
	t2.add(h(x), v * x);
}
ll ck(int mid) {
	return t1.qry(mid) * v[mid - 1] - t2.qry(mid);
}
int main() {
	scanf("%d%d", &n, &qn);
	rep(i, 0, n) scanf("%d", a + i), v.pb(a[i]);
	rep(i, 0, qn) {
		scanf("%d", &q[i].op);
		if (q[i].op == 1) scanf("%d%d", &q[i].x, &q[i].v), q[i].x--, v.pb(q[i].v);
		else scanf("%lld", &q[i].w);
	}
	sort(all(v)); v.erase(unique(all(v)), v.end());
	t1.ini(sz(v)); t2.ini(sz(v));
	rep(i, 0, n) g(a[i], 1);
	rep(i, 0, qn) {
		if (q[i].op == 1) {
			int x = q[i].x;
			g(a[x], -1);
			a[x] = q[i].v;
			g(a[x], 1);
		}
		else {
			int ret;
			for (int l = 1, r = sz(v), mid = l + r >> 1; l <= r; mid = l + r >> 1)
				ck(mid) <= q[i].w ? l = (ret = mid) + 1 : r = mid - 1;
			printf("%.10f\n", v[ret - 1] + (q[i].w - ck(ret)) / (db)t1.qry(ret));
		}
	}
	return 0;
}
