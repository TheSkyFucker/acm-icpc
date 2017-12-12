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
const int MOD = 1e9 + 7;
int x, y;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}
void solve() {
	if (y % x != 0) { puts("0"); return; }
	else y /= x;
	vector<pii> v;
	for (int i = 1; i * i <= y; i++) if (y % i == 0) {
		v.pb({i, i == 1});
		if (i * i < y) v.pb({y / i, 0});
	}
	sort(all(v));
	int ans= 0 ;
	rep(i, 0, sz(v)) {
		int m = y / v[i].fi;
		ans = add(ans, add(MOD, mul(qpow(2, m - 1), v[i].se)));
		rep(j, i + 1, sz(v)) if (v[j].fi % v[i].fi == 0)  {
			v[j].se -= v[i].se;
		}
	}
	printf("%d\n", ans);
}
int main() {
	while (~scanf("%d%d", &x, &y)) solve();
	return 0;
}
