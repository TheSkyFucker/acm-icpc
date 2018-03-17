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
int a, x, y;
int main() {
	scanf("%d%d%d", &a, &x, &y);
	x *= 2, y *= 2;
	if (y % (2 * a) == 0) return 0 * puts("-1");
	if (y < 2 * a && y > 0) {
		return 0 * printf("%d", x > -a && x < a ? 1 : -1);
	}
	for (int px = 1, id = 2, by = 2 * a; ; px = 3 - px, by += 2 * a) {
			if (by + 2 * a > y) {
				if (x == 0 && px == 2 || x <= -px * a || x >= px * a) puts("-1");
				else printf("%d", id + (x > 0 && px == 2));
				return 0;
			}
			id += px;
	}
	return 0;
}
