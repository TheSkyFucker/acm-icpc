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
int n, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	int mx = -INT_MAX, mi = INT_MAX;
  rep(i, 0, n) {
  	mx = max(mx, a[i]);
  	mi = min(mi, a[i]);
	}
	int p1; per(i, 0, n) if (a[i] == mx) p1 = i;
	int p2; rep(i, 0, n) if (a[i] == mi) p2 = i;
	printf("%d", p1 - 1 + n - p2 - (p1 > p2));
	return 0;
}
