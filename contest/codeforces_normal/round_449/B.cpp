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
int P;
int add(int a, int b) { if ((a += b) >= P) a -= P; return a; }
int mul(int a, int b) { return 1ll * a * b % P; }

int n;
int gao(int d) {
	int ret = d % P;
	while (d) {
		ret = add(mul(ret, 10), (d % 10) % P);
		d /= 10;
	}
	return ret;
}

void solve() {
	int ans = 0;
	rep(i, 1, n + 1) ans = add(ans, gao(i));
	printf("%d\n", ans);
}
		
int main() {
	while (~scanf("%d%d", &n, &P)) solve();

	return 0;
}
