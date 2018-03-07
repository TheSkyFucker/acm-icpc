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
const int INF = 1e9 + N; 
int n, m, w, a[N], cnt[N << 1];
bool ck(int lim) {
	int pre = 0; int ned = 0;
	fill_n(cnt, n, 0);
	rep(i, 0, n) {
		pre += cnt[i];
		int tmp = max(0, lim - a[i] - pre); 
		ned += tmp;
		pre += tmp;
		cnt[i + w] -= tmp;
		if (ned > m) return false;
	}
	return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &w);
  rep(i, 0, n) scanf("%d", a + i);
  int ans = 0;
  for (int l = 1, r = INF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
  	ck(mid) ? l = (ans = mid) + 1 : r = mid - 1;
  printf("%d", ans);
	return 0;
}
