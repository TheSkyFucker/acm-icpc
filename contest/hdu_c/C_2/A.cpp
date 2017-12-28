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
const db eps = 1e-7;
bool eq(db a, db b) { return fabs(a - b) < eps; }
void solve() {
	int pos = 0, zero = 0, nag = 0;
	rep(i, 0, n) {
		db d; scanf("%lf", &d);
		if (eq(d, 0)) zero++;
		else if (d > 0) pos++;
		else nag++;
	}
	printf("%d %d %d\n", nag, zero, pos);
}
int main() {
	while (~scanf("%d", &n) && n) solve();

	return 0;
}
