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
#define ext exit(0)
const int N = 2e5 + 7;
int n, m;
char str[N];
struct Fenwick {
	static const int N = ::N;
	int s[N], n;
	void ini(int _n) { fill_n(s + 1, n = _n, 0); }
	void add(int p, int v) { for (; p <= n; p += p & -p) s[p] += v; }
	int qry(int p) { int r = 0; for (; p; p -= p & -p) r += s[p]; return r; }
}	fen;
int getp(int d) {
	int ret = -1;
	for (int l = 1, r = n, mid = l + r >> 1; l <= r; mid = l + r >> 1)
		mid - fen.qry(mid) >= d ? r = (ret = mid) - 1 : l = mid + 1;
	assert(~ret);
	return ret;
}
int getd(char ch) {
	if (ch >= '0' && ch <= '9') return ch - '0';
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 36;
}
#define ls(o) ((o) << 1)
#define rs(o) ((o) << 1 | 1)
char ans[N]; int ansn;
map<ll, char> M;
struct Tree {
	static const int N = ::N << 2;
	ll dp[N];
	void upd(int o) { dp[o] = dp[ls(o)] | dp[rs(o)]; }
	void bud(int o, int l, int r) {
		if (l == r) { dp[o] = 1ll << getd(str[l]); return; }
		int mid = l + r >> 1;
		bud(ls(o), l, mid);
		bud(rs(o), mid + 1, r);
		upd(o);
	}
	int qry(int o, int l, int r, int ql, int qr, int qv) {
		if (!(dp[o] >> qv & 1)) return -1;
		if (l == r) return l;
		int mid = l + r >> 1, tmp;
		if (ql <= mid && ~(tmp = qry(ls(o), l, mid, ql, qr, qv))) return tmp;
		if (qr >  mid && ~(tmp = qry(rs(o), mid + 1, r, ql, qr, qv))) return tmp;
		return -1;
	}
	void del(int o, int l, int r, int qx) {
		if (l == r) { dp[o] = 0; return; }
		int mid = l + r >> 1;
		if (qx <= mid) del(ls(o), l, mid, qx);
		else del(rs(o), mid + 1, r, qx);
		upd(o);
	}
	void dfs(int o, int l, int r) {
		if (l == r) {
			if (dp[o]) ans[ansn++] = M[dp[o]];
			return;
		}
		int mid = l + r >> 1;
		dfs(ls(o), l, mid);
		dfs(rs(o), mid + 1, r);
	}
}	tree;

void solve() {
	scanf(" %s", str + 1);
	tree.bud(1, 1, n);
	fen.ini(n);
	rep(i, 0, m) {
		int l, r; scanf("%d%d", &l, &r);
		char ch; scanf(" %c", &ch);
		l = getp(l);
		r = getp(r);
		//dd(l); de(r);
		int d = getd(ch);
		for (int p; ~(p = tree.qry(1, 1, n, l, r, d)); ) {
			tree.del(1, 1, n, p);
			//de(p);
			fen.add(p, 1);
		}
	}
	ansn = 0;
	tree.dfs(1, 1, n);
	ans[ansn] = '\0';
	puts(ans);
}
int main() {
	for (char ch = '0'; ch <= '9'; ch++) M[1ll << getd(ch)] = ch;
	for (char ch = 'a'; ch <= 'z'; ch++) M[1ll << getd(ch)] = ch;
	for (char ch = 'A'; ch <= 'Z'; ch++) M[1ll << getd(ch)] = ch;
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}
