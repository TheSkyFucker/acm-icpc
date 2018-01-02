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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
const int N = 1e3 + 7;
int n;
db a[N];
void solve() {
	rep(i, 1, n) a[i] = sqrt(a[i - 1]);
	db ans = 0.;
	rep(i, 0, n) ans += a[i];
	printf("%.2f\n", ans);
}
int main() {
	while (~scanf("%lf%d", &a[0], &n)) solve();

	return 0;
}
