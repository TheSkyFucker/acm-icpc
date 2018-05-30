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
int gao(int ai) {
	if (ai == 0) return 0;
	int s = 1;
	if (ai < 0) ai = -ai, s = -1;
	for (int i = 2; i * i <= ai; i++) {
		if (ai % i == 0) {
			int cnt = 0;
			while (ai % i == 0) ai /= i, cnt++;
			if (cnt & 1) s *= i;
		}
	}
	if (ai) s *= ai;
	return s;
}
const int N = 1e4 + 7;
int n, a[N], pre[N], ans[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i], a[i] = gao(a[i]);
	map<int, int> Map;
	rep(i, 0, n) {
		if (Map.count(a[i])) pre[i] = Map[a[i]];
		else pre[i] = -1;
		Map[a[i]] = i;
	}
	rep(l, 0, n) {
		int tmp = 0;
		bool zro = true;
		rep(r, l, n) {
			if (a[r]) tmp += pre[r] < l, zro = false;
			if (!zro) ans[tmp]++;
			else ans[1]++;
		}
	}
	rep(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
		
	return 0;
}
