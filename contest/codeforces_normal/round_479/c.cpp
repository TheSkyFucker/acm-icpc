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
int n, k, a[N];
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	int l = 1, r = 1000000000;
	if (k < n)
		r = min(r, a[k] - 1);
	if (k)
		l = max(l, a[k - 1]);
	if (l > r) return 0 * puts("-1");
	printf("%d", l);
	return 0;
}
