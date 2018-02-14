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
const int N = 1e2 + 7;
int n, ned, has, a[N];
int main() {
	scanf("%d%d%d", &n, &ned, &has);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	rep(i, 0, n) {
		if (has >= ned) return 0 * printf("%d", i);
		has += a[i] - 1;
	}
	return 0 * printf("%d", has >= ned ? n : -1);
}
