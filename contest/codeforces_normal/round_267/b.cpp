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
int n, m, k, a[10000];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 0, m + 1)
		scanf("%d", a + i);
	int ans = 0;
	rep(i, 0, m) if (__builtin_popcount(a[i] ^ a[m]) <= k) ans++;
	printf("%d", ans);
	return 0;
}
