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
const int N = 1e2 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int o[N], x[N], n, k, d;
int gx(int n);
int go(int n) {
	if (n < 0) return 0;
	if (~o[n]) return o[n];
	int &ret = o[n]; ret = 0;
	rep(i, 1, d) ret = add(ret, go(n - i));
	rep(i, d, k + 1) ret = add(ret, add(go(n - i), gx(n - i)));
	return ret;
}
int gx(int n) {
	if (n < 0) return 0;
	if (~x[n]) return x[n];
	int &ret = x[n]; ret = 0;
	rep(i, 1, d) ret = add(ret, gx(n - i));
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &k, &d);
	memset(o, -1, sizeof(o)); o[0] = 0;
	memset(x, -1, sizeof(x)); x[0] = 1;
  printf("%d", go(n));
	return 0;
}
