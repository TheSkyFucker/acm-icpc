
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
const int N = 1e3 + 7;
int n, m, k, p;
int a[N][N];
ll row[N * N], col[N * N];
void gao(ll ans[]) {
	priority_queue<ll> stk;
	rep(i, 0, n) {
		ll tmp = 0; rep(j, 0, m) tmp += a[i][j];
		stk.push(tmp);
	}
	rep(i, 1, k + 1) {
		ll tmp = stk.top(); stk.pop();
		ans[i] = ans[i - 1] + tmp;
		stk.push(tmp - 1ll * p * m);
	}
}
		
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	rep(i, 0, n) rep(j, 0, m) scanf("%d", &a[i][j]);
	gao(row);
	rep(i, 0, max(n, m)) rep(j, i + 1, max(n, m)) swap(a[i][j], a[j][i]);
	swap(n, m);
	gao(col);
	ll ans = -pw(62);
	rep(i, 0, k + 1)
		ans = max(ans, row[i] + col[k - i] - 1ll * i * (k - i) * p);
	printf("%lld", ans);
	return 0;
}
