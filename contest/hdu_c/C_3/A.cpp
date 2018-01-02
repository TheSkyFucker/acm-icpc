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
const int N = 1e2 + 67;
int n;
int a[N];
void solve() {
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	ll tot = 0;
	rep(i, 1, n - 1) tot += a[i];
	printf("%.2f\n", 1. * tot / (n - 2));
}
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}
