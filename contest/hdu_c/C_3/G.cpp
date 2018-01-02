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
const int N = 1e2 + 7;
int n; pii a[N];
void solve() {
	rep(i, 0, n) scanf("%d", &a[i].se), a[i].fi = abs(a[i].se);
	sort(a, a + n);
	per(i, 0, n) printf("%d%c", a[i].se, " \n"[i == 0]);
}
int main() {
	while (~scanf("%d", &n) && n) solve();

	return 0;
}
