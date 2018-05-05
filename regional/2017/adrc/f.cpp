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
// 2 or 3 dx++
// 1 or 2 dy++
pii gao(int n, int cnt) { // n * n
	if (n == 1) return {0, 0};
	int per = n * n / 4;
	int tp = cnt / per;
	pii p = gao(n >> 1, cnt % per);
	if (tp == 0) swap(p.fi, p.se);
	else if (tp == 3)
		p = {n / 2 - 1 - p.se, n / 2 - 1 - p.fi};
	if (tp == 2 || tp == 3) p.fi += n / 2;
	if (tp == 1 || tp == 2) p.se += n / 2;
	return p;
}
int main() {
	int n, cnt; scanf("%d%d", &n, &cnt);
  auto ans = gao(n, cnt - 1);
 /* rep(i, 0, 16) {
  	auto tmp = gao(n, i);
		dd(tmp.fi); de(tmp.se);
	}*/
  printf("%d %d", ans.fi + 1, ans.se + 1);
	return 0;
}
