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
int n, m;
ll cnt[20];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b);
		cnt[b] += a;
	}
	ll ans = 0;
	per(i, 1, 11) {
		int tmp = min((ll)n, cnt[i]);
		n -= tmp;
		ans += 1ll * tmp * i;
	}
	printf("%lld\n", ans);
	
    
	return 0;
}
