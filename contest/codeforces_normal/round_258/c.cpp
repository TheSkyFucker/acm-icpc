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
ll n, k, d1, d2;

void solve() {
	scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
	if (d1 < d2) swap(d1, d2);
	ll mi[] = {d1 + d2, d1 + 2 * d2, d1 * 2 - d2, d2 + 2 * d1};
	ll ned[] = {d1 * 2 - d2, d1 * 2 + d2, d1 + d2, d2 * 2 + d1};
	ll has = n - k;
	rep(i, 0, 4) if (k >= mi[i] && (k - mi[i]) % 3 == 0 && has >= ned[i] && (has - ned[i]) % 3 == 0) {
		puts("yes");
		return;
	}
	puts("no");
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 0, t) solve();
	return 0;
}
