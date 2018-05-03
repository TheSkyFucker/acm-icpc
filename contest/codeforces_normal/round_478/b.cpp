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
int a[100], b[100], n = 14;
int main() {
	rep(i, 0, n) scanf("%d", a + i);
	ll ans = 0;
	rep(i, 0, n) if (a[i]) {
		copy(a, a + n, b);
		int mul = b[i] / 28;
		int tmp = b[i] % 28; b[i] = 0;
		rep(j, 0, tmp) b[(i + 1 + j) % 14]++;
		ll sum = 0;
		rep(j, 0, n) if (!(b[j] & 1)) sum += b[j] + mul * 2;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
