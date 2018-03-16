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
const int N = 1e3 + 7;
int xa, xb, ya, yb, n;
int Sqr(int d) { return d * d; }
struct P { 
	int x, y, r; 
	void read() { scanf("%d%d%d", &x, &y, &r); }
	bool ok(int _x, int _y) {
		return Sqr(x - _x) + Sqr(y - _y) <= Sqr(r); 
	}
}	p[N];

bool gao(int x, int y) {
	rep(i, 0, n) if (p[i].ok(x, y)) return false;
	return true;
}

int main() {
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	scanf("%d", &n);
	rep(i, 0, n) p[i].read();
	if (xa > xb) swap(xa, xb);
	if (ya > yb) swap(ya, yb);
	int ans = 0;
	rep(x, xa, xb + 1) ans += gao(x, ya) + gao(x, yb);
	rep(y, ya + 1, yb) ans += gao(xa, y) + gao(xb, y);
	printf("%d", ans);
	return 0;
}
