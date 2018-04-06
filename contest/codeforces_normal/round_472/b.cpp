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
const int N = 1e5 + 8;
int n, U, e[N];
pii cmp(pii a, pii b) {
	return 1ll * a.fi * b.se <= 1ll * b.fi * a.se ? b : a;
}
int main() {
	scanf("%d%d", &n, &U);
	rep(i, 0, n) scanf("%d", e + i);
	pii ans = {0, 0};
	for (int l = 0, r = 0; l < n; l++) {
		while (r < n && e[r] - e[l] <= U) r++;
		if (r - l < 3) continue;
		ans = cmp(ans, {e[r - 1] - e[l + 1], e[r - 1] - e[l]});
    }
    if (!ans.se) return 0 * puts("-1");
    printf("%.10f\n", (db)ans.fi / ans.se);
	return 0;
}
