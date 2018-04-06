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
const int N = 2e6 + 7;
bool ban[N];
int a[N], b[N], n;
bool ok(int d) {
	vi v;
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0) { 
			v.pb(i);
			if (ban[i]) return false;
			while (d % i == 0) d /= i;
		}
	}
	if (d > 1) {
		if (ban[d]) return false;
		v.pb(d);
	}
	for (auto e : v) if (e < N) ban[e] = true;
	return true;
}
bool isP(int d) {
	for (int i = 2; i * i <= d; i++) if (d % i == 0) return false;
	return true;
}
int main() {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", a + i);
    n = 100000;
    int p = 1;
    rep(i, 0, n) {
    	while (!isP(++p));
    	a[i] = p;
	}
    int pre = 1;
    rep(i, 0, n) {
    	b[i] = a[i];
    	while (!ok(b[i])) b[i]++;
    	if (b[i] == a[i]) continue;
    	int tmp = 1;
		rep(j, i + 1, n) {
			while (!ok(++tmp));
			b[j] = tmp;
		}
		break;
	}
	rep(j, 0, n) printf("%d%c", b[j], " \n"[j == n - 1]);
	return 0;
}
