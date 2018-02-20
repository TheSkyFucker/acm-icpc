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
int n, v;
int main() {
	scanf("%d%d", &n, &v);
	vi ans;
	rep(i, 0, n) {
		int m; scanf("%d", &m);
		bool ok = false;
		rep(j, 0, m) {
			int p; scanf("%d", &p);
			if (v > p) ok = true;
		}
		if (ok) ans.pb(i + 1);
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
	return 0;
}
