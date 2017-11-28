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

const int N = 2e5 + 7;
int n;
char str[N], ban[N];

struct SAM {
	static const int N = ::N << 1;
	int last, m, f[N], mxl[N], nxt[N][26];
	void ini() { last = m = 1; }
	void add(int ch) {
		int p, x; mxl[++m] = mxl[last] + 1;
		for (x = last; x && !nxt[x][ch]; x = f[x]) nxt[x][ch] = m;
		p = nxt[x][ch], last = m;
		if (!x) { f[m] = 1; return; }
		if (mxl[p] == mxl[x] + 1){ f[m] = p; return ;}
		mxl[++m] = mxl[x] + 1, f[m] = f[p], f[p] = f[m - 1] = m;
		rep(i, 0, 26) nxt[m][i] = nxt[p][i];
		for(; x && nxt[x][ch] == p; x = f[x]) nxt[x][ch] = m;
	}
}	sam;

pii a[N << 1];
int cnt[N << 1];
void solve() {
	sam.ini();
	rep(i, 1, n + 1) sam.add(str[i] - 'a');
	int p = 1;
	rep(i, 1, n + 1) {
		p = sam.nxt[p][str[i] - 'a'];
		if (ban[i] == '0') cnt[p]++;
	}
	rep(i, 1, sam.m + 1) a[i] = {sam.mxl[i], i};
	sort(a + 1, a + 1 + sam.m);
	per(i, 1, sam.m + 1) cnt[sam.f[a[i].se]] += cnt[a[i].se];
	ll ans = 0;
	rep(i, 1, sam.m + 1) ans = max(ans, 1ll * cnt[i] * sam.mxl[i]);
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &n);
	scanf(" %s", str + 1);
	scanf(" %s", ban + 1);
	solve();
	return 0;
}
