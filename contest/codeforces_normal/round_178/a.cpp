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
const int N = 1e3 + 7;
int n, m, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 1, n + 1) scanf("%d", a + i);
	scanf("%d", &m);
	rep(i, 0, m) {
		int p, t; scanf("%d%d", &p, &t);;
		if (p > 1) a[p - 1] += t - 1;
		if (p < n) a[p + 1] += a[p] - t;
		a[p] = 0;
	}
	rep(i, 1, n + 1) printf("%d\n", a[i]);
	return 0;
}
