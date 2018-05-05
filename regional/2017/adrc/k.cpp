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
const int N = 1e4 + 7;
int n, ans[N];
int myabs(int d) { return d >= 0 ? d : -d; }
int main() {
  scanf("%d", &n);
  int lx = 0, rx = 1, ly = 0, ry = 0, x = 1, y = 0;
  int cur = 0;
  ans[0] = 1;
  rep(i, 0, n) {
  	int d, op; scanf("%d%d", &d, &op);
  	int nx = x, ny = y;
  	if (cur == 0) if (op == 1) ny = (++ry); else ny = (--ly);
		if (cur == 1) if (op == 1) nx = (--lx); else nx = (++rx);
		if (cur == 2) if (op == 1) ny = (--ly); else ny = (++ry);
		if (cur == 3) if (op == 1) nx = (++rx); else nx = (--lx);
  	cur = (cur + 4 + op) % 4;
  	ans[i + 1] = myabs(nx - x) + myabs(ny - y);
  	x = nx, y = ny;
	}
  rep(i, 0, n) printf("%d%c", ans[i], " \n" [i == n - 1]);
	return 0;
}
