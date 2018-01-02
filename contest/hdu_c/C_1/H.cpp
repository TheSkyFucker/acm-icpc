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
ll l, r;
void solve() {
	ll even = 0, odd = 0;
	if (l > r) swap(l, r);
	for (ll i = l; i < r + 1; i++)  {
		if (i & 1) odd += 1ll * i * i * i;
		else even += 1ll * i * i;
	}
	printf("%lld %lld\n", even, odd);
}
int main() {
	while (~scanf("%lld%lld", &l, &r)) solve();
	return 0;
}
