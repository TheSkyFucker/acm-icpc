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
ll n;
int main() {
    scanf("%lld", &n);
    ll ans = 0;
    for (ll l = 2; l / 2 <= n; l <<= 1) {
    	ll tmp = (n + l / 2 - 1) / l * (l >> 1);
    	ans += tmp;
	}
	cout << ans;
	return 0;
}
