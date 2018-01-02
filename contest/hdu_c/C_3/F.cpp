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
int n, m, a[N];
void solve() {
	rep(i, 0, n) scanf("%d", a + i);
	a[n] = m;
	sort(a, a + 1 + n);
	rep(i, 0, n + 1) printf("%d%c", a[i], " \n"[i == n]);
}
int main() {
	while (~scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) solve();

	return 0;
}
