#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
const int B = 32;
const int N = 2e5 + 7;
int lef[N], rig[N], dig[N], n;
void gao(int bit) {
	int pre = -1;
	rep(i, 0, n) if (dig[i] >> bit & 1) pre = i;
		else rig[i] = min(rig[i], i - 1 - pre);
}	
void solve() {
	rep(i, 0, n) rig[i] = i; 
	rep(i, 0, B) gao(i);
}
pii p[N];
int main() {

	///read
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &dig[i]);

	///prework
	solve();
	rep(i, 0, n) lef[i] = rig[i];
	reverse(dig, dig + n);
	solve();
	for (int i = 0; i < n - 1 - i; i++) swap(rig[i], rig[n - 1 - i]);
	reverse(dig, dig + n);
	
	///work
	ll ans = 1ll * (1 + n) * n / 2;
	rep(i, 0, n) p[i] = mp(dig[i], i);
	sort(p, p + n);
	set<int> S;
	per(i, 0, n) {
		int u = p[i].se;
		auto it = S.lower_bound(u);
		if (it != S.end())   rig[u] = min(rig[u], (*it) - u - 1);
		if (it != S.begin()) lef[u] = min(lef[u], u - 1 - *(--it));
		ans -= 1ll * (lef[i] + 1) * (rig[i] + 1);
		S.insert(u);
	}
	printf("%lld", ans);
	
	return 0;

}
