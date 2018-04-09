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
const int N = 5e5 + 7;
const ll LLINF = 2e18;
int n, R;
ll remain, s[N], a[N];
bool gao(ll lim, ll remain) {
	queue<pair<int, ll> > que;
	ll cur = 0;
	rep(i, 0, n) {
		if (!que.empty() && que.front().fi == i) {
			cur -= que.front().se;
			que.pop();
		}
		if (s[i] + cur >= lim) continue;
		ll ned = lim - s[i] - cur;
		cur += ned;
		if ((remain -= ned) < 0) return false;
		que.push({i + 2 * R + 1, ned});
	}
	return true;
}
int main() {
    scanf("%d%d%lld", &n, &R, &remain);
    rep(i, 0, n) scanf("%lld", &a[i]);
    rep(i, 0, R + 1) s[0] += a[i];
    rep(i, 1, n) {
    	s[i] = s[i - 1];
    	if (i - R - 1 >= 0) s[i] -= a[i - R - 1];
    	if (i + R < n) s[i] += a[i + R];
	}
    ll ret = 0;
    for (ll l = 0, r = LLINF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
		gao(mid, remain) ? l = (ret = mid) + 1 : r = mid - 1;
	cout << ret;
	return 0;
}
