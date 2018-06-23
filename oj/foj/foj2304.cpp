#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
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
const int N = 1e6 + 7, MOD = 1e9 + 7;
int inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int n, m, o[N], v[N];
struct Fenwick {
	static const int N = 5e4 + 7;
	int a[N];
	void add(int p, int v) { for (; p <= n; p += p & -p) inc(a[p], v); }
	int qry(int p) { int r = 0; for (; p; p -= p & -p) inc(r, a[p]); return r; }
}	fen0, fen1;
struct ND {
	int id, a, b, v0, v1;
	ND(){} ND(int id, int a, int b, int v0, int v1) : id(id), a(a), b(b), v0(v0), v1(v1) {}
}	nd[N], nxt_nd[N];
int chg[N], qry[N];
void cdq(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	int beg = l;
	rep(_, 0, 2) {
		int hl = l;
		rep(hr, mid + 1, r + 1) {
			while (hl <= mid && nd[hl].a < nd[hr].a) { 
				int b = nd[hl].b, v0 = nd[hl].v0, v1 = nd[hl].v1;
				fen0.add(b, _ ? MOD - v0 : v0);
				fen1.add(b, _ ? MOD - v1 : v1);
				if (!_) nxt_nd[beg++] = nd[hl];
				hl++;
			}
			if (!_) {
				int b = nd[hr].b - 1;
				inc(chg[nd[hr].id], mul(fen0.qry(b), nd[hr].v1));
				inc(chg[nd[hr].id], mul(fen1.qry(b), nd[hr].v0));
				nxt_nd[beg++] = nd[hr];
			}
		}
		if (!_) {
			while (hl <= mid) nxt_nd[beg++] = nd[hl++];
		}
	}
	rep(_, 0, 2) {
		int hl = mid;
		per(hr, mid + 1, r + 1) {
			while (hl >= l && nd[hl].a > nd[hr].a) {
				int b = n + 1 - nd[hl].b, v0 = nd[hl].v0, v1 = nd[hl].v1;
				fen0.add(b, _ ? MOD - v0 : v0);
				fen1.add(b, _ ? MOD - v1 : v1);
				hl--;
			}
			if (!_) {
				int b = n - nd[hr].b;
				inc(chg[nd[hr].id], mul(fen0.qry(b), nd[hr].v1));
				inc(chg[nd[hr].id], mul(fen1.qry(b), nd[hr].v0));
			}
		}
	}
	copy(nxt_nd + l, nxt_nd + r + 1, nd + l);
}
void solve() {
	cin >> n >> m;
	int idn = 0;
	rep(i, 1, n + 1) { 
		cin >> o[i] >> v[i]; o[i] = n + 1 - o[i];
		++idn; nd[idn] = ND(idn, i, o[i], 1, v[i]);
	}
	rep(i, 1, m + 1){
		int a, b; cin >> a >> b;
		++idn; nd[idn] = ND(idn, a, o[a], MOD - 1, MOD - v[a]);
		++idn; nd[idn] = ND(idn, b, o[b], MOD - 1, MOD - v[b]);
		swap(o[a], o[b]);
		swap(v[a], v[b]);
		++idn; nd[idn] = ND(idn, a, o[a], 1, v[a]);
		++idn; nd[idn] = ND(idn, b, o[b], 1, v[b]);
		qry[i] = idn;
	}
	fill_n(chg + 1, idn, 0);
	cdq(1, idn);
	rep(i, 2, idn + 1) chg[i] = add(chg[i], chg[i - 1]);
	rep(i, 1, m + 1) cout << chg[qry[i]] << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	rep(cas, 0 ,tcas) solve();
	return 0;
}
