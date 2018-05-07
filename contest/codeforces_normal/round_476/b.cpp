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
int n, k, val[N][N];
char tab[N][N];
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 0, n) scanf(" %s", tab[i]);
	rep(i, 0, n) {
	  rep(j, 0, n + 1 - k) {
	  	int sum = 0; rep(l, 0, k) sum += tab[i][j + l] == '.';
	  	if (sum != k) continue;
	  	rep(l, 0, k) val[i][j + l]++;
		}
	}
	rep(j, 0, n) {
		rep(i, 0, n + 1 - k) {
			int sum = 0; rep(l, 0, k) sum += tab[i + l][j] == '.';
			if (sum != k) continue;
			rep(l, 0, k) val[i + l][j]++;
		}
	}
	pair<int, pii> ans = {-1, {0, 0}};
	rep(i, 0, n) rep(j, 0, n) ans = max(ans, {val[i][j], {i, j}});
	//rep(i, 0, n) rep(j, 0, n) printf("%d%c", val[i][j], " \n"[j == n - 1]);
	printf("%d %d\n", ans.se.fi + 1, ans.se.se + 1);
	return 0;
}
