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
const int N = 2e5 + 7;
int n, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &a[i]);
	int ned = -1;
	vi ban;
	rep(i, 0, n - 1) {
		int d1 = min(a[i], a[i + 1]);
		int d2 = max(a[i], a[i + 1]);
		if (d1 == d2) return 0 * puts("NO");
		if (d2 - d1 != 1) {
			if (~ned && ned != d2 - d1) 
				return 0 * puts("NO");
			else
				ned  = d2 - d1;
		}
		else ban.pb(d1);
	}
	if (!~ned) return 0 * printf("YES\n1 %d", 1000000000);
	for (auto e : ban) if (e % ned == 0) {
		return 0 * puts("NO");
	}
	printf("YES\n%d %d", 1000000000, ned);
	return 0;
}
