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
int a[N], n;
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	vector<pii> ans;
  for (int l = 0, r; l < n; l = r + 1) {
  	r = l; while (r + 1 < n && a[r + 1] > a[r]) r++;
  	ans.pb({r - l + 1, l});
	}
/*	for (auto e : ans) {
		dd(e.fi);
		de(e.se);
	}*/
	int mx = 0; rep(i, 0, sz(ans)) mx = max(mx, ans[i].fi);
	rep(i, 0, sz(ans) - 1) {
		mx = max(mx, ans[i].fi + 1);
		mx = max(mx, ans[i + 1].fi + 1);
		if (ans[i].fi > 1 && ans[i + 1].fi > 1 && (
			   a[ans[i + 1].se - 2] + 1 < a[ans[i + 1].se]
			|| a[ans[i + 1].se - 1] + 1 < a[ans[i + 1].se + 1])) {
			mx = max(mx, ans[i].fi + ans[i + 1].fi);
		}
	}
	printf("%d", mx);
	return 0;
}
