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
const int N = 1e7 + 6;
int low[N], isp[N]; vi pri;
void getprime() {
	fill_n(isp + 2, N - 2, 1);
	rep(i, 2, N) {
		if (isp[i]) pri.pb(i);
		for (auto p : pri) {
			if (p * i >= N) break;
			low[p * i] = p;
			isp[p * i] = 0;
			if (i % p == 0) break;
		}
	}
}

int n, a[N];
ll cnt[N];

bool ck(ll mid) {
	for (auto p : pri) {
		ll ned = cnt[p];
		for (ll tmp = mid / p; tmp; tmp /= p) ned -= tmp;
		if (ned > 0) return 0;
	}
	return 1;
}

int main() {
	getprime();
	scanf("%d", &n);
	rep(i, 0, n) {
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	per(i, 2, N - 1) cnt[i] += cnt[i + 1];
	per(i, 2, N - 1) if (!isp[i]) {
		cnt[low[i]] += cnt[i];
		cnt[i / low[i]] += cnt[i];
	}
	ll l = 1, r = 0, ans; rep(i, 0, n) r += a[i];
	for (ll mid = l + r >> 1; l <= r; mid = l + r >> 1)
		ck(mid) ? r = (ans = mid) - 1 : l = mid + 1;
	printf("%lld\n", ans);
	return 0;
}
