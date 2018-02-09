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
int n, m, a, b, d[N][N];

ll dp[N][N];
ll sum[N][N];
ll gsum(int lx, int ly, int rx, int ry) {
	return sum[rx][ry] - sum[lx - 1][ry] - sum[rx][ly - 1] + sum[lx - 1][ly - 1];
}
void ini() {
	rep(i, 1, n + 1) {
		priority_queue<pii> stk;
		per(j, 1, m + 1) {
			stk.push({-d[i][j], j});
			while (stk.top().se >= j + b) stk.pop();
			dp[i][j] = -stk.top().fi;
		}
	}
	rep(j, 1, m + 1) {
		priority_queue<pii> stk;
		per(i, 1, n + 1) {
			stk.push({-dp[i][j], i});
			while (stk.top().se >= i + a) stk.pop();
			dp[i][j] = -stk.top().fi;
		}
	}
	rep(i, 1, n + 1) rep(j, 1, m + 1) {
		sum[i][j] = d[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
}

bool use[N][N];
bool ck(pii p) {
	int x = -p.fi, y = -p.se;
	return !use[x][y] 
		&& !use[x + a - 1][y]
		&& !use[x][y + b - 1]
		&& !use[x + a - 1][y + b - 1];
}
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	rep(i, 1, n + 1) rep(j, 1, m + 1) scanf("%d", &d[i][j]);
	ini();
	priority_queue<pair<ll, pii> > stk;
	rep(i, 1, n + 2 - a) rep(j, 1, m + 2 - b) {
		stk.push({-(gsum(i, j, i + a - 1, j + b - 1) - dp[i][j] * a * b), {-i, -j}});
	}
	vector<pair<ll, pii> > ans;
	while (1) {
		while (!stk.empty() && !ck(stk.top().se)) stk.pop();
		if (stk.empty()) break;
		else ans.pb(stk.top());
		auto e = stk.top().se;
		rep(i, -e.fi, -e.fi + a) rep(j, -e.se, -e.se + b) use[i][j] = true;
	}
	printf("%d\n", sz(ans));
	for (auto e : ans) printf("%d %d %lld\n", -e.se.fi, -e.se.se, -e.fi);
	return 0;
}
