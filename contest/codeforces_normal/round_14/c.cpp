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
bool ck(vi v) {
	sort(all(v));
	for (int l = 0, r; l < sz(v); l = r) {
		r = l; while (r < sz(v) && v[l] == v[r]) r++;
		if (r - l != 4) return false;
	}
	return true;
}
int main() {
	bool ans = true;
	vi vx, vy;
	int px = 0, py = 0;
	rep(i, 0, 4) {
		pii a, b; scanf("%d%d%d%d", &a.fi, &a.se, &b.fi, &b.se);
		if (a.fi == b.fi) py++;
		else if (a.se == b.se) px++;
		vx.pb(a.fi); vx.pb(b.fi);
		vy.pb(a.se); vy.pb(b.se);
	}
	if (px != 2 || py != 2) ans = false;
	if (!ck(vx) || !ck(vy)) ans = false;
	puts(ans ? "YES" : "NO");
    
	return 0;
}
