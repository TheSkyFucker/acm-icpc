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
const int N = 1e6 + 7;
int n, k, ans[N];
int main() {
	scanf("%d%d", &n, &k);
	if (n < 3 * k) return 0 * puts("-1");
	rep(i, 0, k)  ans[i << 1] = ans[i << 1 | 1] = i;
	rep(i, 2 * k, n) ans[i] = i % k;
	rep(i, 0, n) printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
	return 0;
}
