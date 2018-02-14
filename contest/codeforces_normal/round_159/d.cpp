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
const int N = 1e5 + 7;
int a[N], n, ans[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	int p = 0;
	per(i, 0, n) {
		if (p > 0) ans[i + 1] ^= 1, p = -p;
		p += a[i];
	}
	if (p < 0) ans[0] ^= 1;
	int tmp = 0;
	rep(i, 0, n) {
		tmp ^= ans[i];
		putchar(tmp ? '-' : '+');
	}
	return 0;
}
