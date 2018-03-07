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
int n, s;
int mi[1000], mx[1000];
int main() {
	scanf("%d%d", &n, &s);
	if (s == 0 && n > 1) return 0 * printf("-1 -1");
	mi[n -1] = mx[n - 1] = s > 0;
	if (s > 0) s--;
	int _s = s;
	rep(i, 0, n) {
		int tmp = min(s, 9 - mi[i]);
		s -= tmp;
		mi[i] += tmp;
	}
	if (s) return 0 * printf("-1 -1");
	s = _s;
	per(i, 0, n) {
		int tmp = min(s, 9 - mx[i]);
		s -= tmp;
		mx[i] += tmp;
	}
	per(i, 0, n) printf("%d", mi[i]); printf(" ");
	per(i, 0, n) printf("%d", mx[i]);
	return 0;
}
