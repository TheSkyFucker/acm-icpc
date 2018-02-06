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
const int B = 300;
int bn, bl[N], br[N];
int a[N], n, m;
pii ans[N];

void bud(int bi) {
	int l = bl[bi], r = br[bi];
	per(i, l, r) {
		if (i + a[i] >= r) ans[i] = {i, 1};
		else ans[i] = ans[i + a[i]], ans[i].se++;
	}
}

pii qry(int p) {
	pii ret(0, 0);
	while (p < n) {
		ret.fi = ans[p].fi;
		ret.se += ans[p].se;
		p = ans[p].fi;
		p += a[p];
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", a + i);
	bn = (n + B - 1) / B;
	rep(i, 0, bn) bl[i] = i * B, br[i] = (i + 1) * B;
	br[bn - 1] = n;
	rep(i, 0, bn) bud(i);
/*	rep(i, 0, bn) { 
		dd(bl[i]); de(br[i]); 
		rep(j, bl[i], br[i]) de(ans[j].se);
	}*/
	
	rep(i, 0, m) {
		int op; scanf("%d", &op);
		if (op == 0) {
			int p, v; scanf("%d%d", &p, &v); p--;
			a[p] = v;
			bud(p / B);
		}
		else {
			int p; scanf("%d", &p); p--;
			auto ans = qry(p);
			printf("%d %d\n", ans.fi + 1, ans.se);
		}
	}
	return 0;
}
