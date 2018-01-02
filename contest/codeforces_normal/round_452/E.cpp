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
const int N = 2e5 + 7;
int fa[N], sz[N], nxt[N], pre[N], n, a[N];
int getf(int d) { return fa[d] == d ? d : fa[d] = getf(fa[d]); }
void comb(int a, int  b) {
	a = getf(a); b = getf(b);
	sz[b] += sz[a]; fa[a] = b;
}
void solve() {
	rep(i, 1, n + 1) scanf("%d", &a[i]); a[0] = -1; a[n + 1] = -2;
	rep(i, 0, n + 2) fa[i] = i, sz[i] = 1;
	rep(i, 0, n + 1) nxt[i] = i + 1, pre[i + 1] = i;
	per(i, 2, n + 1) if (a[i] == a[i - 1]) {
		nxt[i - 1] = nxt[i];
		comb(i, i - 1);
	}
	priority_queue<pii> stk;
	rep(i, 1, n + 1) {
		int fi = getf(i); if (fi != i) continue;
		stk.push({sz[fi], -fi});
	}
	int ans = 0;
	while (!stk.empty()) {
		int u = -stk.top().se; 
		int s = stk.top().fi; stk.pop();
		//dd(s); de(u);
		int fu = getf(u); if (u != fu || sz[fu] != s) continue;
		int _l = pre[fu], _r = nxt[fu];
		int fl = getf(_l), fr = getf(_r);
		//dd(fl); de(fr);
		ans++;
		if (a[fl] != a[fr]) {
			nxt[fl] = fr;
			pre[fr] = fl;
			comb(fu, 0);
		}
		else {
			nxt[fl] = nxt[fr];
			comb(fr, fl);
			stk.push({sz[fl], -fl});
		}
	}
	printf("%d\n", ans);
}	
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}
