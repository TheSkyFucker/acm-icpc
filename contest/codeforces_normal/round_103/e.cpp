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
const int N  = 1e5 + 7;
int n, m;
vector<pii> g[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int r, c; scanf("%d%d", &r, &c); r--; c--;
		g[r].pb({-c, i + 1});
	}
	priority_queue<pii> stk;
	vi ans;
	per(r, 0, n) {
		for (auto e : g[r]) stk.push(e);
		while (!stk.empty() && -stk.top().fi < n - 1 - r) stk.pop();
		if (!stk.empty()) ans.pb(stk.top().se), stk.pop();
	}
	printf("%d\n", sz(ans));
	sort(all(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
	return 0;
}
