
#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define de(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e5 + 7;
vi G[MAX_N];
///----------------------------------------------
double dfs(int u, int p) {
	int sn = 0;
	double ret = 0.0;
	rep(_v, 0, sz(G[u])) {
		int v = G[u][_v]; if (v == p) continue;
		ret += dfs(v, u);
		sn++;
	}
	if (sn == 0) return 0.0;
	return 1.0 + (ret / sn);
}
	
int main() {

	///read
	int n; cin >> n;
	rep(i, 1, n) {
		int a, b; scanf("%d%d", &a, &b);
		G[a].pb(b);
		G[b].pb(a);
	}

	///prework
	printf("%.10f", dfs(1, 0));
	


}
