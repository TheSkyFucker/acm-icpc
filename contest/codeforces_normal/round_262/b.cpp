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
int a, b, c;
int f(ll d) {
	int r = 0;
	while (d) {
		r += d % 10;
		d /= 10;
	}
	return r;
}
int main() {
	scanf("%d%d%d", &a, &b, &c);
	vector<ll> ans;
	rep(s, 1, 93) {
		ll tmp = b; rep(i, 0, a) tmp *= s;
		tmp += c;
		if (tmp > 0 && tmp < 1e9 && f(tmp) == s) ans.pb(tmp);
	}
  sort(all(ans)); printf("%d\n", sz(ans));
  rep(i, 0, sz(ans)) printf("%lld%c", ans[i], " \n"[i == sz(ans)- 1]);
	return 0;
}
