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
struct Graph {
	static const int N = 50 + 7;
	int n, m, t;
	int a[N * 10], b[N * 10], c[N * 10];
	ll dis[N * N * N][N];
	void read() {
		scanf("%d%d", &n, &m), m += n;
		rep(i, 0, n) scanf("%d", c + i), a[i] = b[i] = i;
		rep(i, n, m) scanf("%d%d%d", a + i, b + i, c + i), a[i]--, b[i]--;
		scanf("%d", &t), t--;
	}
	void solve(int mx) {
		rep(i, 0, mx) fill_n(dis[i], n, LLONG_MAX >> 2);
		dis[0][0] = 0;
		rep(i, 0, mx) rep(j, 0, m) {
			ll &d = dis[i + 1][b[j]];
			d = min(d, dis[i][a[j]] + c[j]);
		}
	}
}	G[3];
int main() {
  int nn; scanf("%d", &nn);
  int mx = 1;
  rep(i, 0, nn) G[i].read(), mx *= G[i].n;
  rep(i, 0, nn) G[i].solve(mx);
  ll ans = LLONG_MAX;
  rep(i, 0, mx) {
  	ll tmp = 0;
  	rep(j, 0, nn) tmp += G[j].dis[i][G[j].t];
		ans = min(ans, tmp);
	}
	printf("%lld", ans);
	return 0;
}
