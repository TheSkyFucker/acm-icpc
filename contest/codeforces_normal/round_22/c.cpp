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
int n, m, s;
int main() {
	scanf("%d%d%d", &n, &m, &s);
	int t = 1; while (t == s) t++;
	set<pii> Set;
	rep(i, 1, n + 1) if (i != s) Set.insert({s, i});
	rep(i, 1, n + 1) if (i != s && i != t) {
		rep(j, i + 1, n + 1) if (j != s && j != t) {
			if (sz(Set) >= m) break;
			Set.insert({i, j});
		}
		if (sz(Set) >= m) break;
	}
	if (sz(Set) != m) { puts("-1"); return 0; }
	for (auto e : Set) printf("%d %d\n", e.fi, e.se);
	return 0;
}
