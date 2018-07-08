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
int n, q, x[N], nxt[N][20], l;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> n;
  rep(i, 0, n) cin >> x[i];
  cin >> l;
  int tmp = 0;
  rep(i, 0, n) {
  	while (tmp + 1 < n && x[tmp + 1] <= x[i] + l) tmp++;
  	nxt[i][0] = tmp;
	}
	rep(j, 1, 20)
		rep(i, 0, n) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	cin >> q;
	rep(i, 0, q) {
		int a, b; cin >> a >> b; a--; b--;
		if (a > b) swap(a, b);
		int ans = 1;
		per(j, 0, 20) if (nxt[a][j] < b) ans += pw(j), a = nxt[a][j];
		cout << ans << endl;
	}
	return 0;
}
