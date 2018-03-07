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
const int N = 3e3 + 7;
int n, m, cnt[N];
vi g[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		g[a].pb(b);
	}
	ll ans = 0;
	rep(i, 0, n) {
		for (auto u : g[i]) {
			for (auto v : g[u]) if (v != i) {
				ans += cnt[v]++;
			}
		}
		rep(j, 0, n) cnt[j] = 0;
	}
	printf("%lld", ans);			
	return 0;
}
