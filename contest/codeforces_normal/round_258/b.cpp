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
int n, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	vi v(a, a + n);
	sort(all(v));
	rep(i, 0, n) a[i] = lower_bound(all(v), a[i]) - v.begin();
	int l = 0; while (l < n - 1 && a[l] == l) l++;
	int r = n - 1; while (r > l && a[r] == r) r--;
	rep(i, l, r + 1) {
		if (a[i] != r - (i - l)) return 0 * puts("no");
	}
	puts("yes");
	printf("%d %d", l + 1, r + 1);
	return 0;
}
