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
const int N = 3e3 + 8;
int n, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	vector<pii> ans;
	rep(i, 0, n) {
		int mi = a[i]; rep(j, i, n) mi = min(mi, a[j]);
		rep(j, i, n) if (a[j] == mi) {
			swap(a[i], a[j]);
			ans.pb({i, j});
			break;
		}
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d %d\n", ans[i].fi, ans[i].se);

    
	return 0;
}
