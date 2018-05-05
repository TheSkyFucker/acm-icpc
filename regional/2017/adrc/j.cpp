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
const int N = 1e2 + 7;
int n, m;
bitset<N> g[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) g[i][i] = 1;
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b), a--, b--;
		g[a][b] = g[b][a] = 1;
	}
	rep(i, 0, n) {
		int ban = 0; rep(j, 0, n) if ((g[i] | g[j]) == g[i]) ban++;
		ban = min(ban, n / 2) - 1;
		int cnt = g[i].count();
		if (cnt - min(cnt, n / 2) - ban <= 0) return 0 * puts("-1");
	} 
	return 0 * puts("1");
}
