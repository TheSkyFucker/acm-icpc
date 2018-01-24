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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
const int N = 1e2 + 7;
int n, T;
pii lim[N];
void solve() {
	int mi = 0, mx = 0;
	rep(i, 0, n) {
		scanf("%d%d", &lim[i].fi, &lim[i].se);
		mi += lim[i].fi;
		mx += lim[i].se;
	}
	if (T < mi || T > mx) { puts("NO"); return; }
	else puts("YES");
	T -= mi;
	rep(i, 0, n) {
		int tmp = min(T, lim[i].se - lim[i].fi);
		T -= tmp;
		printf("%d%c", lim[i].fi + tmp, " \n"[i == n - 1]);
	}
}
int main() {
	while (~scanf("%d%d", &n, &T)) solve();

	return 0;
}