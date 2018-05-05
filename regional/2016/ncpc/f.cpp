#include<bits/stdc++.h>
using namespace std;
typedef long double db;
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
int n, p, x;
int main() {
  scanf("%d%d", &n, &p);
  if (n < p) return 0 * puts("1");
  int x = (n - p + 1 + p - 2) / (p - 1);
	db ans = logl(x) + logl(p);
	rep(i, 2, x + 1) ans += logl(n - p + i);
	rep(i, 1, x + 1) ans -= logl(n + i);
	printf("%.15f\n", (double)expl(ans));
	return 0;
}
