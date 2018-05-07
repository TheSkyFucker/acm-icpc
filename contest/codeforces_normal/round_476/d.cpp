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
const int N = 1e5 + 7, INF = 1e9 + 7;
int n, d, a[N], b[N];
bool ck(int ned) {
	priority_queue<int> stk;
	stk.push(-0);
	rep(i, 0, n + 1) b[i] = 0; b[0] = ned;
	int low = 0;
	rep(i, 1, n + 1) {
		int sto = a[i];
		while (low < i) {
			if (i - low > d) return false;
			int can = min(b[low], sto);
			b[low] -= can;
			b[i] += can;
			sto -= can;
			while (low < n && !b[low]) low++;
			if (!sto) break;
		}
	}
	return true;
}
int main() {
  scanf("%d%d", &n, &d);
  rep(i, 1, n) scanf("%d", a + i); a[n] = INF;
  //n = 100000, d = 2;
  //rep(i, 1, n) a[i] = 10000;
  int ans = 0;
  for (int l = 1, r = INF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
  	ck(mid) ? l = (ans = mid) + 1 : r = mid - 1;
  printf("%d", ans);
	return 0;
}
