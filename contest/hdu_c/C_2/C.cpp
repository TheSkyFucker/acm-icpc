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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
int l, r;
int sqr3(int d) { return d * d * d; }
vi v;

void solve() {
	int beg = lower_bound(all(v), l) - v.begin();
	int lim = upper_bound(all(v), r) - v.begin();
	if (beg == lim) { puts("no"); return; }
	rep(i, beg, lim) printf("%d%c", v[i], " \n"[i == lim - 1]);
}

int main() {
	rep(i, 1, 10) rep(j, 0, 10) rep(k, 0, 10) {
		int d1 = sqr3(i) + sqr3(j) + sqr3(k);
		int d2 = i * 100 + j * 10 + k;
		if (d1 == d2) v.pb(d1);
	}
	while (~scanf("%d%d", &l, &r)) solve();

	return 0;
}
