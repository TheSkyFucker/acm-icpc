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
int n, m, a, b[N], p[N];
bool ck(int mid) {
	reverse(p, p + mid);
	int has = a;
	rep(i, 0, mid) {
		int ned = max(0, p[i] - b[i]);
		if ((has -= ned) < 0) break;
	}
	reverse(p, p + mid);
	return has >= 0;
}
int main() {
	scanf("%d%d%d", &n, &m, &a);
	rep(i, 0, n) scanf("%d", b + i); sort(b, b + n); reverse(b, b + n);
	rep(i, 0, m) scanf("%d", p + i); sort(p, p + m);
	int can = 0;
	for (int l = 1, r = min(n, m), mid = l + r >> 1; l <= r; mid = l + r >> 1) 
		ck(mid) ? l = (can = mid) + 1 : r = mid - 1;
	printf("%d ", can);
	reverse(p, p + can);
	int ans = 0, has = a;
	rep(i, 0, can) {
		int ned = max(0, p[i] - b[i]); //de(ned);
		ans += min(p[i], b[i]);
		has -= ned;
	}
	printf("%d", max(0, ans - has));
	return 0;
}
