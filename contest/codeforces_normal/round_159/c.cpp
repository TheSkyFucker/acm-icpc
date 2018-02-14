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
const db pi = acos(-1);
int n;
db a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		db x, y; scanf("%lf%lf", &x, &y);
		a[i] = atan2(y, x);
	}
	sort(a, a + n);
	rep(i, 0, n) a[i + n] = a[i] + 2. * pi;
	db ans = 2. * pi;
	rep(i, 0, n) {
		ans = min(ans, a[i + n - 1] - a[i]);
	}
	printf("%.12f", ans / pi * 180.); 
	return 0;
}
