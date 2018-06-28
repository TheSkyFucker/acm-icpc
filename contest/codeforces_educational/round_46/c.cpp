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
const int N = 2e5 + 7;
int n;
ll ans[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  vector<pair<ll, int> > v;
  cin >> n;
  rep(i, 0, n) {
  	ll l, r; cin >> l >> r;
  	v.pb({l, 1});
  	v.pb({r + 1, -1});
	}
	sort(all(v));
	int tmp = 0; ll pre = 0;
	for (auto e : v) {
		ans[tmp] += e.fi - pre;
		tmp += e.se;
		pre = e.fi;
	}
	rep(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
	return 0;
}
