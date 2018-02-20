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
int n, v, cnt[10000];
int main() {
	scanf("%d%d", &n, &v);
	rep(i, 0, n) {
		int a, b; scanf("%d%d", &a, &b);
		cnt[a] += b;
	}
	int pre = 0, ans = 0;
	rep(i, 1, 3010) {
		int can = v;
		int tmp1 = min(pre, can);
		can -= tmp1;
		ans += tmp1;
		pre = cnt[i];
		int tmp2 = min(pre, can);
		ans += tmp2;
		pre -= tmp2;
	}
	printf("%d", ans);
	return 0;
}
