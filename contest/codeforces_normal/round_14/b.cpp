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
int n, x0;
int main() {
  scanf("%d%d", &n, &x0);
  int l = -1000, r = 1001;
  rep(i, 0, n) {
  	int a, b; scanf("%d%d", &a ,&b);
  	if (a > b) swap(a, b);
  	l = max(l, a);
  	r = min(r ,b);
	}
	if (l > r) puts("-1");
	else if (x0 >= l && x0 <= r) puts("0");
	else if (x0 < l) printf("%d\n", l - x0);
	else printf("%d\n", x0 - r);
	return 0;
}
