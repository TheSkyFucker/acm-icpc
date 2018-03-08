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
const int N = 1e5 + 7;
int mk[N], n, a[N], pos[N];
bool isP(int d) {
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0) return false;
	}
	return true;
}
int main() {
	rep(i, 2, N) mk[i] = isP(i) ? i : mk[i - 1];
	scanf("%d", &n);
	rep(i, 1, n + 1) scanf("%d", a + i), pos[a[i]] = i;
	vector<pii> ans;
	rep(i, 1, n + 1) {
		int p = pos[i];
		while (p != i) {
			int l = mk[p - i + 1];
			ans.pb({p, p - l + 1});
			swap(a[p], a[p - l + 1]);
			pos[a[p]] = p;
			p = p - l + 1;
		}
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d %d\n", ans[i].se, ans[i].fi);
	return 0;
}
