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
const int N = 1e2 + 7;
ll a[N];
int n;
int cnt(ll d, int x) { int r = 0; while (d % x == 0) d /= x, r++; return r; }
bool cmp(const ll &a, const ll &b) {
	int acnt3 = cnt(a, 3), bcnt3 = cnt(b, 3);
	if (acnt3 != bcnt3) return acnt3 > bcnt3;
	int acnt2 = cnt(a, 2), bcnt2 = cnt(b, 2);
	return acnt2 < bcnt2;
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%lld", a + i);
	sort(a, a + n, cmp);
	rep(i, 0, n) printf("%lld%c", a[i], " \n"[i == n - 1]);
	return 0;
}
