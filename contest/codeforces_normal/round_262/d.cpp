#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
//typedef vector<int> vi;
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
ll l, r;
int k;

typedef vector<ll> vl;
typedef pair<ll, vl> T;

T g1() {
	return {l, vl() = {l}};
}

T g2() {
	if (r - l + 1 == 2) return {l ^ r, vl() = {l, r}};
	return {1, vl() = {l + (l & 1), l + (l & 1) + 1}};
}

T g3() {
	int tmp = 0;
	rep(i, 0, 60) if (pw(i) & l) tmp = i;
	ll mx = pw(tmp) * 3; 
	if (mx > r) return {l + 1, vl()};
	return {0, vl() = {l, l ^ mx, mx}};
}

T g4() {
	T ret = {l ^ (l + 1) ^ (l + 2) ^ (l + 3), vl() = {l, l + 1, l + 2, l + 3}};
	if (r - l + 1 >= 5) {
		ret.fi = 0;
		rep(i, 0, 4) ret.se[i] += l & 1;
	}
	return ret;
}

int main() {
  scanf("%lld%lld%d", &l, &r, &k);
  T r[4], ans;
  rep(i, 0, 4) r[i].fi = l + 1;
	if (k >= 1) r[0] = g1();
	if (k >= 2) r[1] = g2();
	if (k >= 3) r[2] = g3();
	if (k >= 4) r[3] = g4();
	ll mi = l + 1; rep(i, 0, 4) mi = min(mi, r[i].fi);
	rep(i, 0, 4) if (r[i].fi == mi) ans = r[i];
	printf("%lld\n", mi);
	printf("%d\n", sz(ans.se));
	rep(i, 0, sz(ans.se)) printf("%lld%c", ans.se[i], " \n"[i == sz(ans.se) - 1]);
	return 0;
}
