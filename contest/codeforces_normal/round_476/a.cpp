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
const int INF = 1e9 + 7;
int k, n, s, p;
ll f(int x) { return (x * 1ll * p) / k * s - n; }
int main() {
	scanf("%d%d%d%d", &k, &n, &s, &p);
	int ret = -1;
	for (int l = 1, r = INF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
		f(mid) >= 0 ? r = (ret = mid) - 1 : l = mid + 1;
	printf("%d", ret);
	return 0;
}
