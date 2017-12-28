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
int n;
void solve() {
	scanf("%d", &n);
	db ans = 0.;
	rep(i, 1, n + 1) {
		if (i & 1) ans += 1. / i;
		else ans -= 1. / i;
	}
	printf("%.2f\n", ans);
}
int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 1, tcase + 1) solve();

	return 0;
}
