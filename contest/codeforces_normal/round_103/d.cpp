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
int n, m, s;
vector<pii> g[N];
int dis[N], in[N];
void Spfa(int S) {
	fill_n(dis, n, INT_MAX); dis[S] = 0;
	fill_n(in, n, 0); in[S] = 1;
	queue<int> que; que.push(S);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for(auto v : g[u]) {
			if (dis[v.fi] > dis[u] + v.se) {
				dis[v.fi] = dis[u] + v.se;
				if (!in[v.fi]) {
					in[v.fi] = true;
					que.push(v.fi);
				}
			}
		}
		in[u] = false;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s); s--;
	rep(i, 0, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	Spfa(s);
	int ned; scanf("%d", &ned);
	int ans = 0;
	rep(i, 0, n) ans += dis[i] == ned;
	rep(i, 0, n) {
		for (auto j : g[i]) if (i < j.fi) {
			int mi = min(dis[i], dis[j.fi]);
			int mx = max(dis[i], dis[j.fi]);
			int l = j.se;
			if (mx < ned && 2 * mx + (mi + l - mx) >= 2 * ned) ans++;
			if (mi < ned && 2 * mi + 2 * l - (mi + l - mx) > 2 * ned) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
