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
vi v;
int l, r;
int f(int d) { return d * d + d + 41; }
bool isp(int d) {
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0) return false;
	}
	return true;
}
void solve() {
	int pl = lower_bound(all(v), l) - v.begin();
	int pr = upper_bound(all(v), r) - v.begin();
	puts(r - l + 1 == pr - pl ? "OK" : "Sorry");
}
int main() {
	rep(i, -39, 51) if (isp(f(i))) v.pb(i);
	while (~scanf("%d%d", &l, &r) && !(l == 0 && r == 0)) solve();
	return 0;
}
