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
int deg1[N], deg2[N], n, m;
vi g1[N], g2[N];
int dp[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b);
		g1[a].pb(b);
		g1[b].pb(a);
		deg1[a]++;
		deg1[b]++;
	}
	rep(u, 0, n) {
		for (auto v : g1[u]) {
			if (deg1[v] > deg1[u]) {
				g2[v].pb(u);
				deg2[u]++;
			}
		}
	}
	rep(i, 0, n) dp[i] = 1;
	queue<int> que;
	rep(u, 0, n) if (!deg2[u]) que.push(u);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto v : g2[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			if (!--deg2[v]) que.push(v);
		}
	}
	printf("%d", *max_element(dp, dp + n));
	return 0;
}
